#include "two_sum.h"

namespace two_sum {

std::vector<int> TwoSumArray(const std::vector<int>& nums, int target) {
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

}  // namespace two_sum
