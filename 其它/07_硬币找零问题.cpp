/**
假设有 1 元，3 元，5 元的硬币若干（无限），现在需要凑出 11 元，问如何组合才能使硬币的数量最少？

动态规划：
定义dp[i]表示凑出i需要的最少的硬币数。
dp[0] = 0
dp[i] = min(dp[i-1]+1, dp[i-3]+1, dp[i-5]+1)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    int money;
    cin >> money;
    int dp[100];
    for (int i = 0; i < 100; ++i) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= money; ++i) {
        for (auto coin: coins) {
            dp[i] = min(dp[i], dp[i-coin]+1);
        }
    }
    cout << dp[money] << endl;
    return 0;
}
/**
3
1 3 5
11

3
*/
