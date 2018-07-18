#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 1;
        return int(pow(2, number-1));
    }
};

int main() {
    int number;
    cin >> number;
    Solution s;
    cout << s.jumpFloorII(number);
    return 0;
}
