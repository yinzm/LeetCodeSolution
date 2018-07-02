#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            cash = max(cash, hold+prices[i]-fee);
            hold = max(hold, cash-prices[i]);
        }
        return cash;
    }
};

int main() {
    Solution s;
    vector<int> prices;
    int n, x;
    int fee;
    cin >> fee;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        prices.push_back(x);
    }
    cout << s.maxProfit(prices, fee);
    return 0;
}
