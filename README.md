# Project 0 — Two Sum (CS351)

Two C++ implementations of LeetCode #1 ([Two Sum](https://leetcode.com/problems/two-sum/)),
with unit tests, GitHub Actions CI, and Docker packaging.

| Function | Approach | Time | Space |
| --- | --- | --- | --- |
| `TwoSumArray` | Brute-force nested loop | O(n²) | O(1) |
| `TwoSumHashTable` | Single-pass hash map | O(n) avg | O(n) |

See [`docs/algorithm.md`](docs/algorithm.md) for the full complexity discussion.

## Repository layout

```
.
├── CMakeLists.txt
├── Dockerfile
├── .github/workflows/ci.yml
├── src/
│   ├── two_sum.h
│   ├── two_sum_array.cpp     # O(n²) implementation
│   ├── two_sum_hash.cpp      # O(n) implementation
│   └── main.cpp              # interactive driver
├── tests/
│   ├── CMakeLists.txt
│   └── test_two_sum.cpp      # GoogleTest, parametrized over both impls
└── docs/
    ├── overview.md
    ├── algorithm.md
    └── build-and-run.md
```

## Build & run locally

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
ctest --test-dir build --output-on-failure   # 28 tests (14 cases × 2 impls)
./build/two_sum                              # interactive driver
```

Detailed instructions: [`docs/build-and-run.md`](docs/build-and-run.md).

## Run with Docker

The Docker build runs the full test suite during the builder stage; the
build fails if any test fails.

```bash
docker build -t two_sum .
docker run --rm -i two_sum
```

## CI

GitHub Actions runs two jobs on every push and pull request to `main`:

1. **Build & test** — native Ubuntu build, runs `ctest` over both
   `TwoSumArray` and `TwoSumHashTable`.
2. **Docker build** — builds the multi-stage image, which itself runs
   `ctest` inside the builder stage.

Workflow: [`.github/workflows/ci.yml`](.github/workflows/ci.yml).
