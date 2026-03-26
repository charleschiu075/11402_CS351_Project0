#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSumHash(const vector<int>& nums, int target) {
    unordered_map<int, int> valueToIndex;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        const int complement = target - nums[i];

        auto match = valueToIndex.find(complement);
        if (match != valueToIndex.end()) {
            return {match->second, i};
        }

        valueToIndex[nums[i]] = i;
    }

    return {};
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    vector<int> answer = twoSumHash(nums, target);
    if (!answer.empty()) {
        cout << "[" << answer[0] << ", " << answer[1] << "]\n";
    } else {
        cout << "No valid pair found.\n";
    }

    return 0;
}