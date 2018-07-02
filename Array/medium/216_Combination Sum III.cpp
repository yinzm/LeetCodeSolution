#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        dfs(res, ans, 1, k, n, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& ans, int start, int k, int n, int sum) {
        if (ans.size() == k && sum == n) {
            res.push_back(ans);
            return ;
        }
        if (sum > n) return ;
        for (int i = start; i <= 9; ++i) {
            ans.push_back(i);
            dfs(res, ans, i+1, k, n, sum+i);
            ans.pop_back();
        }
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
