#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        ans[0][0] = grid[0][0];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) continue;
                int upX = i-1, upY = j;
                int leftX = i, leftY = j-1;
                int temp = INT_MAX;
                if (upX >= 0 && upX < row && upY >= 0 && upY < col) temp = min(temp, ans[upX][upY]);
                if (leftX >= 0 && leftX < row && leftY >= 0 && leftY < col) temp = min(temp, ans[leftX][leftY]);
                ans[i][j] = grid[i][j] + temp;
            }
        }
        return ans[row-1][col-1];
    }
};

int main() {
    Solution s;
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << s.minPathSum(grid) << endl;
    }
    return 0;
}
