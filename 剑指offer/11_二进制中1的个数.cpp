#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
        unsigned flag = 1;
        int cnt = 0;
        while (flag) {
            if (n & flag) cnt++;
            flag = flag << 1;
        }
        return cnt;
     }
     int NumberOf1II(int n) {
        int cnt = 0;
        while (n) {
            cnt++;
            n = (n&(n-1));
        }
        return cnt;
     }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.NumberOf1II(n) << endl;
}
/**
-1
32

0
0
*/
