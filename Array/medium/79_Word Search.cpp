#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() <= 0 || word.size() <= 0) return false;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> vis(row, vector<bool>(col, false));
                    vis[i][j] = true;
                    if (searchWord(i, j, 0, row, col, board, word, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool searchWord(int x, int y, int step, int row, int col, vector<vector<char>>& board,
             const string& word, vector<vector<bool>>& vis) {
        if (board[x][y] != word[step]) {
            return false;
        }
        if (step >= word.size()-1) {
            return true;
        }
        bool res = false;
        for (int i = 0; i < 4; ++i) {
            int nextX = x+dx[i];
            int nextY = y+dy[i];
            if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && !vis[nextX][nextY]) {
                vis[nextX][nextY] = true;
                res |= searchWord(nextX, nextY, step+1, row, col, board, word, vis);
                if (res) return true;
                vis[nextX][nextY] = false;
            }
        }
        return res;
    }
private:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
};

int main() {
    Solution s;
    int n, m;
    string word;
    while (cin >> n >> m) {
        cin >> word;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> board[i][j];
            }
        }
        cout << s.exist(board, word) << endl;
    }
    return 0;
}
/**
3 4
ABCCED
A B C E
S F C S
A D E E
1

3 4
SEE
A B C E
S F C S
A D E E
1

3 4
ABCB
A B C E
S F C S
A D E E
0
*/
