#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<bool>& vis, vector<int>& nums, int cur, int sum, int k, int n) {
        if (cur >= k) {
            if (sum == n) {
                ans.push_back(nums);
            }
            return ;
        }
        if (sum > n) return ;
        int i = cur?nums[cur-1]+1:1;
        for (; i <= 9; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                nums[cur] = i;
                dfs(ans, vis, nums, cur+1, sum+i, k, n);
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> vis(10, false);
        vector<vector<int>> ans;
        vector<int> nums(k, 0);
        vis[0] = true;
        dfs(ans, vis, nums, 0, 0, k, n);
        return ans;
    }
};

int main() {
    Solution s;
    int k, n;
    cin >> k >> n;
    vector<vector<int>> ans = s.combinationSum3(k, n);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
