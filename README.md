# Two Sum Array (C++)

This project solves the Two Sum problem for an integer array in C++.
The implementation uses a hash map (`unordered_map`) to achieve linear time lookup.

## Problem

Given an integer array `nums` and an integer `target`, return the indices of two numbers such that they add up to `target`.

## Project Structure

- `src/` contains source code.
- `docs/` contains project documentation.
- `README.md` is the root project overview.

## Build

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp -o two_sum
```

## Run

```bash
./two_sum
```

## Example

Input:

```text
4
2 7 11 15
9
```

Output:

```text
[0, 1]
```

## Documentation

- `docs/overview.md`
- `docs/algorithm.md`
- `docs/build-and-run.md`
- `docs/examples.md`