#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }
        int dp[len+1][2]; // 第一维代表第几个价格，第二维代表是否手头有该物品，0代表没有物品，1代表有。
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 2; i <= len; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i-1]);
        }
        return max(dp[len][0], dp[len][1]);
    }
    // greed method, official solution
    // link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/
    int maxProfit2(vector<int>& prices) {
        int len = prices.size();
        if (len <= 1) {
            return 0;
        }
        int maxP = 0;
        for (int i = 1; i < len; ++i) {
            if (prices[i] > prices[i-1]) {
                maxP += (prices[i] - prices[i-1]);
            }
        }
        return maxP;
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
    cout << s.maxProfit2(prices) << endl;
    return 0;
}
