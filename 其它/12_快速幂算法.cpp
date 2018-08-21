#include <bits/stdc++.h>
using namespace std;

int fastPow(int base, int n) {
    int res = 1;
    int temp = base;
    while (n) {
        if (n&0x1) {
            res *= temp;
        }
        temp *= temp;
        n >>= 1;
    }
    return res;
}
int fastPow2(int base, int n) {
    if (n == 0) return 1;
    if (n == 1) return base;
    int res = fastPow2(base, n>>1);
    res *= res;
    if (n&0x1) {
        res *= base;
    }
    return res;
}
int main() {
    int n;
    while (cin >> n) {
        cout << fastPow(2, n) << endl;
    }
    return 0;
}
