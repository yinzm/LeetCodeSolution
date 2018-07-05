#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(int left, int right, vector<int>& nums, int val) {
        int mid = left+(right-left)/2;
        while (left < right) {
            if (nums[mid] >= val) {
                right = mid;
            } else {
                left = mid+1;
            }
            mid = left+(right-left)/2;
        }
        return right;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = 0, distance = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size()-1; ++j) {
                int x = target - nums[i] - nums[j];
                int loc = binarySearch(j+1, nums.size(), nums, x);
                if (loc < nums.size()) {
                    int temp_dist = abs(x - nums[loc]);
                    if (temp_dist < distance) {
                        distance = temp_dist;
                        closest = nums[i]+nums[j]+nums[loc];
                    }
                }
                if (loc > j+1) {
                    int temp_dist = abs(x - nums[loc-1]);
                    if (temp_dist < distance) {
                        distance = temp_dist;
                        closest = nums[i]+nums[j]+nums[loc-1];
                    }
                }
            }
        }
        return closest;
    }
};

int main() {
    Solution s;
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << s.threeSumClosest(nums, target);
    return 0;
}
/**
4 1
-1 2 1 -4
*/
