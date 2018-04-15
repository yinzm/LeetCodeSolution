#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int dp[1010];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < len; ++i) {
            dp[i] = min(dp[i-1]+cost[i], dp[i-2]+cost[i]);
        }
        return min(dp[len-1], dp[len-2]);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> cost(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    Solution s;
    cout << s.minCostClimbingStairs(cost) << endl;
    return 0;
}
