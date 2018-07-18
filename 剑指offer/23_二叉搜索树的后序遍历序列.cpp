#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& sequence, int left, int right) {
        if (left >= right) return true;
        int pos = left;
        for (int i = left; i < right; ++i) {
            if (sequence[i] < sequence[right]) {
                pos++;
            } else {
                break;
            }
        }
        for (int i = pos; i < right; ++i) {
            if (sequence[i] < sequence[right]) {
                return false;
            }
        }
        return check(sequence, left, pos-1) && check(sequence, pos, right-1);
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) return false;
        if (sequence.size() == 1) return true;
        int left = 0, right = sequence.size()-1;
        return check(sequence, left, right);
    }
};

int main() {
    Solution s;
    while (true) {
        int n;
        cin >> n;
        vector<int> sequence(n);
        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
        }
        cout << s.VerifySquenceOfBST(sequence) << endl;
    }
    return 0;
}
/**
6
3 6 5 11 10 9
1

1
3
1

2
3 6
1

2
6 3
1

6
2 3 6 7 1 4
0
*/
