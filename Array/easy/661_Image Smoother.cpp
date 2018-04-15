#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size();
        int col = M[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < row; ++i) {
            vector<int> r;
            for (int j = 0; j < col; ++j) {
                int val = getVal(i, j, M);
                r.push_back(val);
            }
            ans.push_back(r);
        }
        return ans;
    }
    int getVal(int x, int y, vector<vector<int>>& M) {
        int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
        int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
        int row = M.size();
        int col = M[0].size();
        int val = M[x][y], cnt = 1;
        for (int i = 0; i < 8; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < row && yy >= 0 && yy < col) {
                val += M[xx][yy];
                cnt ++;
            }
        }
        return val/cnt;
    }
};
int main() {
    int n,m;
    int x;
    vector<vector<int>> M;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            row.push_back(x);
        }
        M.push_back(row);
    }
    Solution s;
    vector<vector<int>> ans = s.imageSmoother(M);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
