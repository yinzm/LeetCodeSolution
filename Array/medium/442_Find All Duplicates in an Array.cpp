#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != i+1) {

                int temp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[ nums[i]-1 ] = temp;
                i--;
            }
        }
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
