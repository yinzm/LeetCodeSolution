#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> triangle;
        triangle.push_back(1);
        if (rowIndex == 0) {
            return triangle;
        }
        triangle.push_back(1);
        if (rowIndex == 1) {
            return triangle;
        }
        for (int r = 2; r <= rowIndex; ++r) {
            for (int c = r-1; c > 0; --c) {
                triangle[c] = triangle[c] + triangle[c-1];
            }
            triangle[0] = 1;
            triangle.push_back(1);
        }
        return triangle;
    }
};

int main() {
    Solution s;
    int k;
    while (cin >> k) {
        vector<int> v = s.getRow(k);
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
