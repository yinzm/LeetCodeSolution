#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        if (len <=0) return -1;
        int max_indx = 0;
        bool flag = true;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[max_indx]) {
                if (nums[i] < (nums[max_indx]*2)) {
                    flag = false;
                } else {
                    flag = true;
                }
                max_indx = i;
            } else if (nums[i] > double(nums[max_indx]/2.0)) {
                flag = false;
            }
        }
        if (flag) {
            return max_indx;
        } else {
            return -1;
        }
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
    cout << s.dominantIndex(nums);
    return 0;
}
