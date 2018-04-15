#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int val = len*(len+1)/2;
        for (int i = 0; i < len; ++i) {
            val -= nums[i];
        }
        return val;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}
