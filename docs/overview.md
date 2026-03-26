# Overview

## Project

Two Sum Array in C++: find two indices in an integer array whose values add up to a target.

## Directory Layout

- `src/main.cpp`: source code
- `docs/`: documentation files
- `README.md`: root-level project summary

## Approach

The program scans the array once and stores previously seen values in a hash map (`value -> index`).
When processing a value `x`, it checks if `target - x` has already appeared.

## Complexity

- Time complexity: O(n)
- Space complexity: O(n)
