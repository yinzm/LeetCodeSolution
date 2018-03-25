#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid = l+(r-l)/2;
        while (l < r) {
            if (nums[mid] > target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid+1;
            } else {
                return mid;
            }
            mid = l+(r-l)/2;
        }
        return l;// upper_bound
        // if you use "r = mid-1, l = mid", you will get the lower_bound
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
