#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y) {
        int row = grid.size(), col = grid[0].size();
        if (x+2 >= row || y+2 >= col) return false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[x+i][y+j] > 9 || grid[x+i][y+j] < 1)
                    return false;
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[x+i][y+j];
            }
            if (i == 0) {
                ans = sum;
            } else {
                if (sum != ans) return false;
            }
            sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[x+j][y+i];
            }
            if (sum != ans) return false;
        }
        if (grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2] != ans) return false;
        if (grid[x+2][y]+grid[x+1][y+1]+grid[x][y+2] != ans) return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (check(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}
