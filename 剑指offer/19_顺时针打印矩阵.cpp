#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int bright = matrix[0].size();
        int bdown = matrix.size();
        int bleft = -1;
        int bup = -1;
        int x = 0, y = 0;
        while (true) {
            while (y<bright) {
                res.push_back(matrix[x][y]);
                y++;
            }
            y--;
            bup++;
            x++;
            if (bdown-bup == 1) break;
            while (x<bdown) {
                res.push_back(matrix[x][y]);
                x++;
            }
            x--;
            bright--;
            y--;
            if (bright-bleft == 1) break;
            while (y>bleft) {
                res.push_back(matrix[x][y]);
                y--;
            }
            y++;
            bdown--;
            x--;
            if (bdown-bup == 1) break;
            while (x>bup) {
                res.push_back(matrix[x][y]);
                x--;
            }
            x++;
            bleft++;
            y++;
            if (bright-bleft == 1) break;
        }
        return res;
    }
    vector<int> printMatrix2(vector<vector<int>> matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col-1, top = 0, bottom = row-1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            for (int i = top+1; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (top != bottom) {
                for (int i = right-1; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
            }
            if (left != right) {
                for (int i = bottom-1; i > top; --i) {
                    res.push_back(matrix[i][left]);
                }
            }
            left++, right--, top++, bottom--;
        }
        return res;
    }
};

int main() {
    return 0;
}
