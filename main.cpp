#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seenIndex;

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        int complement = target - nums[i];

        if (seenIndex.find(complement) != seenIndex.end()) {
            return {seenIndex[complement], i};
        }

        seenIndex[nums[i]] = i;
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

    vector<int> answer = twoSum(nums, target);
    if (!answer.empty()) {
        cout << "[" << answer[0] << ", " << answer[1] << "]\n";
    } else {
        cout << "No valid pair found.\n";
    }

    return 0;
}