#include <iostream>
#include <vector>

#include "two_sum.h"

namespace {

void PrintResult(const char* label, const std::vector<int>& result) {
    std::cout << label << ": ";
    if (result.empty()) {
        std::cout << "no valid pair found\n";
        return;
    }
    std::cout << "[" << result[0] << ", " << result[1] << "]\n";
}

}  // namespace

int main() {
    int n = 0;
    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    std::vector<int> nums(static_cast<std::size_t>(n));
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> nums[static_cast<std::size_t>(i)])) {
            std::cerr << "Invalid input.\n";
            return 1;
        }
    }

    int target = 0;
    std::cout << "Enter the target number: ";
    if (!(std::cin >> target)) {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    PrintResult("TwoSumArray    ", two_sum::TwoSumArray(nums, target));
    PrintResult("TwoSumHashTable", two_sum::TwoSumHashTable(nums, target));
    return 0;
}
