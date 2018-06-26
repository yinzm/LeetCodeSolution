#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre = max(pre+nums[i], nums[i]);
            ans = max(ans, pre);
        }
        return ans;
    }

    // divide and conquer method
    // great explanation https://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int max(int a, int b, int c) {
        return max(a, max(b, c));
    }

    int max_cross_sum(vector<int>& nums, int l, int mid, int r) {
        int max_left = INT_MIN, sum_left = 0;
        for (int i = mid; i >= l; --i) {
            sum_left += nums[i];
            max_left = max(max_left, sum_left);
        }
        int max_right = INT_MIN, sum_right = 0;
        for (int i = mid+1; i <= r; ++i) {
            sum_right += nums[i];
            max_right = max(max_right, sum_right);
        }
        return max_left+max_right;
    }

    int divid_conquer(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nums[l];
        }

        int mid = (l+r)/2;
        return max(divid_conquer(nums, l, mid),
                   divid_conquer(nums, mid+1, r),
                   max_cross_sum(nums, l, mid, r));
    }

    int maxSubArray2(vector<int>& nums) {
        return divid_conquer(nums, 0, nums.size()-1);
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
    cout << s.maxSubArray2(nums);
    return 0;
}
/**
9
-2 1 -3 4 -1 2 1 -5 4
*/
