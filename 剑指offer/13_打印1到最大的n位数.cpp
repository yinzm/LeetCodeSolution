#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void print1ToMaxOfNDigits(int n) {
        if (n <= 0) return ;
        int *number = new int[n];
        memset(number, 0, n);
        while (Increment(number, n)) {
            printNumber(number, n);
        }
        delete[] number;
        return ;
    }
    bool Increment(int *number, int len) {
        int carry = 0;
        for (int i = len-1; i >= 0; --i) {
            number[i] = number[i]+carry;
            if (i == len-1) number[i]++;
            carry = number[i]/10;
            number[i] %= 10;
        }
        if (carry > 0) return false;
        return true;
    }
    void printNumber(int *number, int len) {
        bool zero = true;
        for (int i = 0; i < len; ++i) {
            if (number[i]) {
                zero = false;
                for (int j = i; j < len; ++j) {
                    cout << number[j];
                }
                cout << endl;
                break;
            }
        }
        if (zero) cout << '0' << endl;
    }
};
class Solution2 {
public:
    void print1ToMaxOfNDigits(int n) {
        if (n <= 0) return ;
        int *number = new int[n];
        memset(number, 0, n);
        printRecursively(number, n, 0);
        delete[] number;
        return ;
    }
    void printRecursively(int *number, int len, int index) {
        if (index >= len) {
            printNumber(number, len);
            return ;
        }
        for (int i = 0; i < 10; ++i) {
            number[index] = i;
            printRecursively(number, len, index+1);
        }
    }
    void printNumber(int *number, int len) {
        bool zero = true;
        for (int i = 0; i < len; ++i) {
            if (number[i]) {
                zero = false;
                for (int j = i; j < len; ++j) {
                    cout << number[j];
                }
                cout << endl;
                break;
            }
        }
        if (zero) cout << '0' << endl;
    }
};

int main() {
    int n;
    cin >> n;
    Solution2 s;
    s.print1ToMaxOfNDigits(n);
    return 0;
}
