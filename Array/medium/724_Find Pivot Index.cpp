#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return -1;
        }
        vector<int> l2r, r2l;
        int lsum = 0;
        for (int i = 0; i < len; ++i) {
            l2r.push_back(lsum);
            lsum += nums[i];
        }
        int rsum = 0;
        for (int i = len-1; i >= 0; --i) {
            r2l.push_back(rsum);
            rsum += nums[i];
        }
        for (int i = 0; i < len; ++i) {
            if (l2r[i] == r2l[len-i-1]) {
                return i;
            }
        }
        return -1;
    }
    int pivotIndex2(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return -1;
        }
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        int left_sum = 0;
        for (int i = 1; i < len; ++i) {
            if (left_sum == (sum - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.pivotIndex2(nums);
    return 0;
}
/**
6
1 7 3 6 5 6
*/
