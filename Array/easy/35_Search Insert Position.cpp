#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len, mid = l+(r-l)/2;
        while (l < r) {
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid+1;
            }
            mid = l+(r-l)/2;
        }
        return r;
    }
};

int main() {
    Solution s;
    int n, k, x;
    while (cin >> n >> k) {
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            nums.push_back(x);
        }
        cout << s.searchInsert(nums, k) << endl;
    }
    return 0;
}
