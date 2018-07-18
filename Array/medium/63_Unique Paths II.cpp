#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        if (!obstacleGrid[0][0]) ans[0][0] = 1;
        else ans[0][0] = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j]) continue;
                int upX = i-1, upY = j;
                int leftX = i, leftY = j-1;
                ans[i][j] = 0;
                if (upX >= 0 && upX < row && upY >= 0 && upY < col && !obstacleGrid[upX][upY]) ans[i][j] += ans[upX][upY];
                if (leftX >= 0 && leftX < row && leftY >= 0 && leftY < col && !obstacleGrid[leftX][leftY]) ans[i][j] += ans[leftX][leftY];
            }
        }
        return ans[row-1][col-1];
    }
};

int main() {
    Solution s;
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> obstacleGrid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> obstacleGrid[i][j];
            }
        }
        cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    }
    return 0;
}
