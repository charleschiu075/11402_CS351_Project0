#pragma once

#include <vector>

namespace two_sum {

// Brute-force nested-loop approach.
// Time:  O(n^2)
// Space: O(1)
// Returns the indices of the two numbers that add up to `target`.
// Returns an empty vector if no such pair exists.
std::vector<int> TwoSumArray(const std::vector<int>& nums, int target);

// Hash-table single-pass approach.
// Time:  O(n) average
// Space: O(n)
// Returns the indices of the two numbers that add up to `target`.
// Returns an empty vector if no such pair exists.
std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target);

}  // namespace two_sum
