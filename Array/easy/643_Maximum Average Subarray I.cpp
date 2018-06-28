#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = INT_MIN;
        int len = nums.size();
        vector<int> cumulative_sum;
        for (int i = 0; i < len; ++i) {
            if (i == 0) {
                cumulative_sum.push_back(nums[i]);
            } else {
                cumulative_sum.push_back(cumulative_sum[i-1]+nums[i]);
            }
        }
        for (int i = len-1; i >= 0; --i) {
            int j = i-k;
            if (j >= 0) {
                sum = max(sum , cumulative_sum[i] - cumulative_sum[j]);
            } else if (j == -1) {
                sum = max(sum, cumulative_sum[i]);
            }
        }
        return double(sum)/double(k);
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int n, k, x;
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.findMaxAverage(nums, k);
    return 0;
}
