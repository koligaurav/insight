#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> closestToZero(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    int minSum = INT_MAX;
    int minDiff = INT_MAX;
    int result1, result2;

    while (left < right) {
        int currentSum = nums[left] + nums[right];
        int currentDiff = abs(currentSum);

        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            minSum = currentSum;
            result1 = nums[left];
            result2 = nums[right];
        }

        if (currentSum < 0) {
            left++;
        }
        else if (currentSum > 0) {
            right--;
        }
        else {
            // Found a pair with sum = 0
            return { nums[left], nums[right] };
        }
    }

    return { result1, result2 };
}

int main() {
    vector<int> nums = { -1, 2, -3, 4, -5, 6 };
    vector<int> result = closestToZero(nums);

    cout << "Closest Pair: " << result[0] << ", " << result[1] << endl;

    return 0;
}