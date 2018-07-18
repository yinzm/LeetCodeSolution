#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int row = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = row-1; i >= 0; --i) {
            for (int j = col-1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution s;
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        s.setZeroes(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/**
3 5
-4 -2 6 -7 0
-8 6 -8 -6 0
2 2 -9 -6 10
*/
