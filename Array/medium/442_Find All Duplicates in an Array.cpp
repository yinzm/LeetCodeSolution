#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int idx = 0, len = nums.size();
        while (idx < len) {
            if (nums[idx] != idx+1) {
                int toIdx = nums[idx]-1;
                if (nums[toIdx] != toIdx+1) {
                    swap(nums[idx], nums[toIdx]);
                } else {
                    idx++;
                }
            } else {
                idx++;
            }
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i+1) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
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
    vector<int> ans = s.findDuplicates(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
