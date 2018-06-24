#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 0) return 0;
        int p1 = 0, p2 = 0;
        int min_point = prices[0], max_point = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > max_point) {
                p2 = i;
                max_point = prices[i];
            } else if (prices[i] < min_point) {
                max_profit = max(max_profit, max_point - min_point);
                p1 = i;
                min_point = prices[p1];
                p2 = i;
                max_point = prices[p2];
            }
        }
        max_profit = max(max_profit, max_point - min_point);
        return max_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        prices.push_back(x);
    }
    cout << s.maxProfit(prices);
    return 0;
}
