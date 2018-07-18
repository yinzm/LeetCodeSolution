#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1;
        int val = 1;
        while (x1 <= x2 && y1 <= y2) {
            for (int i = y1; i <= y2; ++i) {
                matrix[x1][i] = val++;
            }
            for (int i = x1+1; i <= x2; ++i) {
                matrix[i][y2] = val++;
            }
            if (x1 < x2) {
                for (int i = y2-1; i >= y1; --i) {
                    matrix[x2][i] = val++;
                }
            }
            if (y1 < y2) {
                for (int i = x2-1; i > x1; --i) {
                    matrix[i][y1] = val++;
                }
            }
            x1++;
            y1++;
            x2--;
            y2--;
        }
        return matrix;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        vector<vector<int>> matrix = s.generateMatrix(n);
        for (auto vec: matrix) {
            for (auto x: vec) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
