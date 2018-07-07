#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, closest = INT_MAX;
        for (int i = 0; i < nums.size()-2; ++i) {
            int second = i+1, third = nums.size()-1;
            while (second < third) {
                int val = nums[i]+nums[second]+nums[third];
                if (abs(val - target) < closest) {
                    closest = abs(val - target);
                    ans = val;
                }
                if (val > target) {
                    third--;
                } else if (val < target) {
                    second++;
                } else {
                    return target;
                }
            }
        }
        return ans;
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
