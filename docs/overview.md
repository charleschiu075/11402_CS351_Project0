# Project Overview

## Goal

Solve the Two Sum problem in C++ using a hash-based approach.

## Input and Output

- Input:
  - Number of elements `n`
  - `n` integers
  - Target integer
- Output:
  - Indices of two elements that sum to target, printed as `[i, j]`

## Key Idea

Use a hash map (`unordered_map`) to store values already seen and their indices.
For each current value `x`, look for `target - x` in the hash map.

## Complexity

- Time: O(n)
- Space: O(n)

## Source File

- `src/main.cpp`
