#include "two_sum.h"

#include <unordered_map>

namespace two_sum {

std::vector<int> TwoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> value_to_index;
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        const int complement = target - nums[i];
        const auto match = value_to_index.find(complement);
        if (match != value_to_index.end()) {
            return {match->second, i};
        }
        value_to_index[nums[i]] = i;
    }
    return {};
}

}  // namespace two_sum
