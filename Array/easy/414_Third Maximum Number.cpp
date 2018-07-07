#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1, max2, max3;
        max1 = max2 = max3 = LLONG_MIN;
        for (auto x: nums) {
            if (x == max1 || x == max2 || x <= max3) continue;
            if (max1 == LLONG_MIN || x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (max2 == LLONG_MIN || x > max2) {
                max3 = max2;
                max2 = x;
            } else if (max3 == LLONG_MIN || x > max3) {
                max3 = x;
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }

    int thirdMax2(vector<int>& nums) {
        long long max1, max2, max3;
        max1 = max2 = max3 = LLONG_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= max3 || nums[i] == max2 || nums[i] == max1) continue;
            max3 = nums[i];
            if (max3 > max2) swap(max3, max2);
            if (max2 > max1) swap(max2, max1);
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << s.thirdMax(nums);
    return 0;
}
