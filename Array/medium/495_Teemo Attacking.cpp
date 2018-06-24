#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        int len = timeSeries.size();
        for (int i = 0; i < len; ++i) {
            ans += duration;
            if (i<len-1) {
                int val = (timeSeries[i] + duration -1);
                if (val >= timeSeries[i+1]) {
                    ans -= (val-timeSeries[i+1]+1);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> timeSeries;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        timeSeries.push_back(x);
    }
    int duration;
    cin >> duration;
    cout << s.findPoisonedDuration(timeSeries, duration);
    return 0;
}
