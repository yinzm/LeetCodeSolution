#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        int cnt = 1, flag = nums[0], max_len = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > flag) {
                cnt++;
                flag = nums[i];
            } else {
                max_len = max(max_len, cnt);
                flag = nums[i];
                cnt = 1;
            }
        }
        max_len = max(max_len, cnt);
        return max_len;
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
    cout << s.findLengthOfLCIS(nums);
    return 0;
}
