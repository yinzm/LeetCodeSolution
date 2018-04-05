#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt = 0, currentCnt = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i]) {
                currentCnt++;
            } else {
                maxCnt = max(currentCnt, maxCnt);
                currentCnt = 0;
            }
        }
        maxCnt = max(maxCnt, currentCnt);
        return maxCnt;
    }
};
int main() {
    Solution s;
    int n, x;
    vector<int>nums;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
