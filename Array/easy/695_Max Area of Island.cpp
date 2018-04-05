#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j]) {
            grid[i][j] = 0;
            return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
        } else {
            return 0;
        }
    }
};

int main() {
    Solution s;
    int n, m, x;
    vector<vector<int>> grid;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
