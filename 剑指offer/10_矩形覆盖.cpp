#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if (number <= 2) return number;
        int a = 1, b = 2;
        for (int i = 3; i <= number; ++i) {
            int val = a+b;
            a = b;
            b = val;
        }
        return b;
    }
};

int main() {
    return 0;
}
