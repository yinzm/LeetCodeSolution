#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0, k = col-1; j <= k; ++j, --k) {
                int temp = A[i][j];
                A[i][j] = A[i][k] ? 0 : 1;
                A[i][k] = temp ? 0 : 1;
            }
        }
        return A;
    }
};

int main() {
    Solution s;
    vector<vector<int>> A, B;
    int r, c;
    cin >> r >> c;
    int val;
    for (int i = 0; i < r; ++i) {
        vector<int> v;
        for (int j = 0; j < c; ++j) {
            cin >> val;
            v.push_back(val);
        }
        A.push_back(v);
    }
    B = s.flipAndInvertImage(A);
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
