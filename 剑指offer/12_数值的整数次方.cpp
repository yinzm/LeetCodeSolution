#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (isEqual(base, 0.0) && exponent < 0) {
            return 0;
        }
        bool neg = false;
        if (exponent < 0) {
            neg = true;
            exponent = -exponent;
        }
        double res = powerCore(base, exponent);
        if (neg) {
            return 1.0/res;
        } else {
            return res;
        }
    }
    bool isEqual(double a, double b) {
        double eps = 1e-8;
        if (abs(a-b) <= eps) return true;
        else return false;
    }
    double powerCore(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        double res = powerCore(base, exponent>>1);
        res *= res;
        if (exponent & 1) {
            res *= base;
        }
        return res;
    }
};

int main() {
    Solution s;
    double base;
    int exponent;
    while (cin >> base >> exponent) {
        cout << s.Power(base, exponent) << endl;
    }
    return 0;
}
