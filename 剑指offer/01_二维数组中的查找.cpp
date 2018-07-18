#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int row = array.size();
        int col = array[0].size();
        if (row == 0 || col == 0) return false;
        int x = 0, y = col-1;
        while (x>=0 && x<row && y>=0 && y<col) {
            if (array[x][y] == target) return true;
            else if (array[x][y] < target) x++;
            else y--;
        }
        return false;
    }
};

int main() {
    int row, col, target;
    cin >> row >> col >> target;
    vector<vector<int>> array;
    vector<int> line(col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> line[j];
        }
        array.push_back(line);
    }
    Solution s;
    cout << s.Find(target, array);
    return 0;
}
/**
4 4 7
1 2 8 9
2 4 9 12
4 7 10 13
6 8 11 15

3 3 7
1 2 3
4 7 9
5 8 10
*/
