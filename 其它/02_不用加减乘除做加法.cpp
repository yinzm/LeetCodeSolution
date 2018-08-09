#include <bits/stdc++.h>
using namespace std;

// 非递归实现
int addMethod(int a, int b) {
    int sum, carry;
    do {
        sum = a^b;
        carry = (a&b)<<1;
        a = sum;
        b = carry;
    } while (carry);
    return a;
}

// 递归实现
int addMethod2(int a, int b) {
    if (b == 0) return a;
    int sum = a^b;
    int carry = (a&b)<<1;
    return addMethod2(sum, carry);
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        cout << addMethod2(a, b) << endl;
    }
    return 0;
}
