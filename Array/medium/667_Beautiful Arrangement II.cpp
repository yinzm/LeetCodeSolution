#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= n-k-1; ++i) {
            ans.push_back(i);
        }
        int val = n-k-1;
        int head = 1, tail = k+1;
        for (int i = 0; i <= k; ++i) {
            if (i%2 == 0) {
                ans.push_back(head+val);
                head++;
            } else {
                ans.push_back(tail+val);
                tail--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n, k;
    cin >> n >> k;
    vector<int> ans = s.constructArray(n, k);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
