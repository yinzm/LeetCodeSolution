#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        int _min = nums[0], _max = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(_min, _max);
            }
            _min = min(nums[i], nums[i]*_min);
            _max = max(nums[i], nums[i]*_max);

            res = max(res, _max);
        }
        return res;
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << s.maxProduct(nums) << endl;
    }
    return 0;
}
