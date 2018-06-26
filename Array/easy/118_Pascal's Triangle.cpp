#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        vector<int> row;
        row.push_back(1);
        ans.push_back(row);
        if (numRows == 1) return ans;
        for (int i = 1; i < numRows; ++i) {
            vector<int> row;
            row.push_back(1);
            for (int j = 1; j < i; ++j) {
                row.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> ans = s.generate(n);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
