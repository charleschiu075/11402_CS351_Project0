# Overview

## Problem

Given an array of integers `nums` and an integer `target`, return the
indices of the two numbers that add up to `target`.

- Each input has exactly one solution.
- The same element may not be used twice.
- The order of the returned indices is not constrained.

LeetCode reference: <https://leetcode.com/problems/two-sum/>

## Goals

This project implements and compares two algorithmic approaches:

1. **`TwoSumArray`** — nested-loop brute force. Establishes a correctness
   baseline and demonstrates the cost of a quadratic scan.
2. **`TwoSumHashTable`** — single-pass hash map. Trades extra memory for
   linear time by remembering values already seen and looking up the
   complement in O(1) average.

Both functions share an identical signature:

```cpp
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);
```

They return the two indices on success and an empty vector when no pair
exists. Returning empty (rather than asserting) makes the functions safe
to test on edge inputs (empty array, single element, no solution).

## Deliverables

- Two implementations (`src/two_sum_array.cpp`, `src/two_sum_hash.cpp`).
- Comprehensive unit tests parametrized over both implementations, so a
  single failure surfaces a divergence between the two.
- GitHub Actions CI running both implementations on every push and PR.
- Multi-stage Dockerfile that runs the test suite during the build.
- Complexity analysis ([`algorithm.md`](algorithm.md)).
