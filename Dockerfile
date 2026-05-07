# syntax=docker/dockerfile:1.6

# ---- Stage 1: build & test ----
FROM gcc:13 AS builder

# CMake from gcc:13's Debian base
RUN apt-get update \
 && apt-get install -y --no-install-recommends cmake ca-certificates \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY CMakeLists.txt ./
COPY src/ ./src/
COPY tests/ ./tests/

RUN cmake -S . -B /build -DCMAKE_BUILD_TYPE=Release \
 && cmake --build /build -j"$(nproc)"

# Build fails if any test fails — packaging the solution requires green tests.
RUN ctest --test-dir /build --output-on-failure

# ---- Stage 2: minimal runtime ----
FROM debian:bookworm-slim AS runtime

RUN apt-get update \
 && apt-get install -y --no-install-recommends libstdc++6 \
 && rm -rf /var/lib/apt/lists/*

COPY --from=builder /build/two_sum /usr/local/bin/two_sum

ENTRYPOINT ["/usr/local/bin/two_sum"]
