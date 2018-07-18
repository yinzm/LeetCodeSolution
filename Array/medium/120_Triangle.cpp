#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (triangle.size() <= 0) return 0;
        vector<int> sum(row);
        sum[0] = triangle[0][0];
        for (int i = 1; i < row; ++i) {
            for (int j = i; j >= 0; j--) {
                if (j == i) {
                    sum[j] = sum[j-1] + triangle[i][j];
                } else if (j == 0) {
                    sum[j] += triangle[i][j];
                } else {
                    sum[j] = min(sum[j-1], sum[j]) + triangle[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (auto x: sum) {
            res = min(res, x);
        }
        return res;
    }
};

int main() {
    Solution s;
    int row, col;
    while (cin >> row >> col) {
        vector<vector<int>> triangle(row, vector<int>(col));
        for (int i = 1; i <= row; ++i) {
            for (int j = 0; j < i; ++j) {
                cin >> triangle[i-1][j];
            }
        }
        cout << s.minimumTotal(triangle) << endl;
    }
    return 0;
}
/**
4 4
2
3 4
6 5 7
4 1 8 3

*/
