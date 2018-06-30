#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        vector<bool> vis(len, false);
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            if (!vis[i]) {
                int cnt = 1;
                vis[i] = true;
                int next_index = nums[i];
                while (true) {
                    if (nums[next_index] == nums[i]) break;
                    vis[next_index] = true;
                    cnt++;
                    next_index = nums[next_index];
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
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
    cout << s.arrayNesting(nums);
    return 0;
}
