# Build & Run

## Prerequisites

- CMake 3.16+
- A C++17 compiler (GCC 9+, Clang 10+, AppleClang 12+)
- Network access on the first configure (CMake fetches GoogleTest via
  `FetchContent`)

## Local build

```bash
# Configure (Release; debug info via -DCMAKE_BUILD_TYPE=Debug if preferred)
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release

# Build everything in parallel
cmake --build build -j
```

Build outputs:

- `build/two_sum` — interactive driver executable
- `build/libtwo_sum_lib.a` — static library exposing both `TwoSum*`
  functions
- `build/tests/two_sum_tests` — GoogleTest binary

## Run the tests

```bash
ctest --test-dir build --output-on-failure
```

This runs **28 tests**: 14 scenarios parametrized over both
`TwoSumArray` and `TwoSumHashTable`. Failures surface immediately as
a divergence between the two implementations.

You can also run the test binary directly for richer GoogleTest output:

```bash
./build/tests/two_sum_tests
./build/tests/two_sum_tests --gtest_filter=*Duplicates*
```

## Run the interactive driver

```bash
$ ./build/two_sum
Enter number of elements: 4
Enter 4 integers: 2 7 11 15
Enter the target number: 9
TwoSumArray    : [0, 1]
TwoSumHashTable: [0, 1]
```

## Docker

```bash
# Builds the image; ctest is executed inside the builder stage,
# so the build fails if any test fails.
docker build -t two_sum .

# Run the driver in a container (interactive stdin).
docker run --rm -i two_sum <<'EOF'
4
2 7 11 15
9
EOF
```

## Disabling tests for a faster build

```bash
cmake -S . -B build -DTWO_SUM_BUILD_TESTS=OFF
cmake --build build -j
```

This skips the GoogleTest fetch and the test target, leaving only the
library and the `two_sum` driver.
