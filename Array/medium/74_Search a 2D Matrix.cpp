#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() <= 0) return false;
        int row = matrix.size(), col = matrix[0].size();
        int x = 0, y = col-1;
        while (x >= 0 && x < row && y >= 0 && y < col) {
            if (matrix[x][y] < target) {
                x++;
            } else if (matrix[x][y] > target) {
                y--;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    int n, m, target;
    while (cin >> n >> m >> target) {
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        cout << s.searchMatrix(matrix, target) << endl;
    }
    return 0;
}
/**
3 4 3
1 3 5 7
10 11 16 20
23 30 34 50

3 4 13
1 3 5 7
10 11 16 20
23 30 34 50
*/
