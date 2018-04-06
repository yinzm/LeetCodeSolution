#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        int dp[len+1][2];
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 2; i <= len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1]);
        }
        return max(dp[len][0], dp[len][1]);
    }
};

int main() {
    Solution s;
    int n, x;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        prices.push_back(x);
    }
    cout << s.maxProfit(prices) << endl;
    return 0;
}
