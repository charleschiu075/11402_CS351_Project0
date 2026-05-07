#include "two_sum.h"

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

namespace {

using TwoSumFn = std::vector<int> (*)(const std::vector<int>&, int);

// Canonicalize the returned pair as a sorted {min, max} so tests don't
// depend on which index each implementation discovers first.
std::vector<int> Sorted(std::vector<int> v) {
    std::sort(v.begin(), v.end());
    return v;
}

// Parametrize each scenario over both implementations so a single test
// failure surfaces a divergence between brute-force and hash-table.
class TwoSumTest : public ::testing::TestWithParam<TwoSumFn> {};

TEST_P(TwoSumTest, LeetCodeExample) {
    const std::vector<int> nums = {2, 7, 11, 15};
    EXPECT_EQ(Sorted(GetParam()(nums, 9)), (std::vector<int>{0, 1}));
}

TEST_P(TwoSumTest, ResultIndicesNotMiddleOfArray) {
    const std::vector<int> nums = {3, 2, 4};
    EXPECT_EQ(Sorted(GetParam()(nums, 6)), (std::vector<int>{1, 2}));
}

TEST_P(TwoSumTest, DuplicatesUseEachElementOnce) {
    const std::vector<int> nums = {3, 3};
    EXPECT_EQ(Sorted(GetParam()(nums, 6)), (std::vector<int>{0, 1}));
}

TEST_P(TwoSumTest, DuplicatesAmongOthers) {
    const std::vector<int> nums = {1, 5, 5, 11};
    EXPECT_EQ(Sorted(GetParam()(nums, 10)), (std::vector<int>{1, 2}));
}

TEST_P(TwoSumTest, AllNegativeNumbers) {
    const std::vector<int> nums = {-1, -2, -3, -4, -5};
    EXPECT_EQ(Sorted(GetParam()(nums, -8)), (std::vector<int>{2, 4}));
}

TEST_P(TwoSumTest, MixedSignsTargetingZero) {
    const std::vector<int> nums = {-3, 4, 3, 90};
    EXPECT_EQ(Sorted(GetParam()(nums, 0)), (std::vector<int>{0, 2}));
}

TEST_P(TwoSumTest, MixedSignsTargetingNegative) {
    const std::vector<int> nums = {-10, 7, 19, -4};
    EXPECT_EQ(Sorted(GetParam()(nums, -14)), (std::vector<int>{0, 3}));
}

TEST_P(TwoSumTest, ContainsZero) {
    const std::vector<int> nums = {0, 4, 3, 0};
    EXPECT_EQ(Sorted(GetParam()(nums, 0)), (std::vector<int>{0, 3}));
}

TEST_P(TwoSumTest, FirstAndLastIndices) {
    const std::vector<int> nums = {5, 1, 2, 3, 7};
    EXPECT_EQ(Sorted(GetParam()(nums, 12)), (std::vector<int>{0, 4}));
}

TEST_P(TwoSumTest, IntBoundaryValues) {
    // Use values that fit safely as int and exercise large magnitudes.
    const std::vector<int> nums = {1000000, -1000000, 5, 7};
    EXPECT_EQ(Sorted(GetParam()(nums, 0)), (std::vector<int>{0, 1}));
}

TEST_P(TwoSumTest, NoSolutionReturnsEmpty) {
    const std::vector<int> nums = {1, 2, 3, 4};
    EXPECT_TRUE(GetParam()(nums, 100).empty());
}

TEST_P(TwoSumTest, EmptyInputReturnsEmpty) {
    const std::vector<int> nums;
    EXPECT_TRUE(GetParam()(nums, 0).empty());
}

TEST_P(TwoSumTest, SingleElementReturnsEmpty) {
    const std::vector<int> nums = {5};
    EXPECT_TRUE(GetParam()(nums, 5).empty());
    EXPECT_TRUE(GetParam()(nums, 10).empty());
}

TEST_P(TwoSumTest, LargerArrayPairAtEnd) {
    std::vector<int> nums(1000);
    for (int i = 0; i < 1000; ++i) {
        nums[static_cast<std::size_t>(i)] = i;
    }
    // 998 + 999 = 1997
    EXPECT_EQ(Sorted(GetParam()(nums, 1997)), (std::vector<int>{998, 999}));
}

INSTANTIATE_TEST_SUITE_P(
    BothImplementations,
    TwoSumTest,
    ::testing::Values(&two_sum::TwoSumArray, &two_sum::TwoSumHashTable),
    [](const ::testing::TestParamInfo<TwoSumFn>& info) {
        return info.param == &two_sum::TwoSumArray ? "TwoSumArray"
                                                   : "TwoSumHashTable";
    });

}  // namespace
