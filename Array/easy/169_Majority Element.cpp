#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int majorityEle = nums[0];
        int cnt = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] == majorityEle) {
                cnt++;
            } else {
                if (cnt == 0) {
                    majorityEle = nums[i];
                    cnt = 1;
                } else {
                    cnt--;
                }
            }
        }
        return majorityEle;
    }
};

int main() {
    Solution s;
    int n, x;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.majorityElement(nums) << endl;
    return 0;
}
