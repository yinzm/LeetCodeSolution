#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        for (int i = 0; i < len;) {
            if (i == len-1 && bits[i] == 0) {
                return true;
            }
            if (bits[i]) {
                i += 2;
            } else {
                i++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    int n, x;
    vector<int> bits;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        bits.push_back(x);
    }
    cout << s.isOneBitCharacter(bits) << endl;
    return 0;
}
