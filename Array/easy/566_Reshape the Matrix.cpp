#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        int m = nums[0].size();
        if (r*c != n*m)
            return nums;
        vector<vector<int>> newMatrix;
        for (int i = 0; i < r; ++i) {
            vector<int> row;
            for (int j = 0; j < c; ++j) {
                int idx = i*c + j;
                row.push_back(nums[idx/m][idx%m]);
            }
            newMatrix.push_back(row);
        }
        return newMatrix;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums, out;
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        vector<int> row;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            row.push_back(x);
        }
        nums.push_back(row);
    }
    int r, c;
    cin >> r >> c;
    out = s.matrixReshape(nums, r, c);
    for (int i = 0; i < out.size(); ++i) {
        vector<int> row = out[i];
        for (int j = 0; j < row.size(); ++j) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
