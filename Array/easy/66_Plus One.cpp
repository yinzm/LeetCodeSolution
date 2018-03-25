#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[len-1]++;
        int carry = 0;
        for (int i = len-1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        vector<int> newDigits;
        if (carry) {
            newDigits.push_back(carry);
        }
        for (int i = 0; i < len; ++i) {
            newDigits.push_back(digits[i]);
        }
        return newDigits;
    }

    // better idea!!
    vector<int> plusOne2(vector<int>& digits) {
        int len = digits.size();
        for (int i = len-1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main() {
    Solution s;
    int n, x;
    while (cin >> n) {
        vector<int> digits;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            digits.push_back(x);
        }
        vector<int> newDigits = s.plusOne2(digits);
        for (int i = 0; i < newDigits.size(); ++i) {
            cout << newDigits[i];
        }
        cout << endl;
    }
    return 0;
}
