#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t row = matrix.size();
        size_t column = matrix[0].size();
        for (size_t i = 0; i < column; ++i) {
            int val = matrix[0][i];
            for (size_t r = 1, c = i+1; r < row && c < column; ++r, ++c) {
                if (matrix[r][c] != val) {
                    return false;
                }
            }
        }
        for (size_t i = 1; i < row; ++i) {
            int val = matrix[i][0];
            for (size_t r = i+1, c = 1; r < row && c < column; ++r, ++c) {
                if (matrix[r][c] != val) {
                    return false;
                }
            }
        }
        return true;
    }
    // clean code
    bool isToeplitzMatrix2(vector<vector<int>>& matrix) {
        size_t row = matrix.size(), column = matrix[0].size();
        for (size_t r = 1; r < row; ++r) {
            for (size_t c = 1; c < column; ++c) {
                if (matrix[r][c] != matrix[r-1][c-1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    int M, N, x;
    while (cin >> M >> N) {
        vector<vector<int>> matrix;
        for (int i = 0; i < M; ++i) {
            vector<int> row;
            for (int j = 0; j < N; ++j) {
                cin >> x;
                row.push_back(x);
            }
            matrix.push_back(row);
        }
        cout << s.isToeplitzMatrix(matrix) << endl;
    }
    return 0;
}
