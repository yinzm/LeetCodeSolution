#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size();
        vector<int> cnt;
        for (int i = 0; i < len; ++i) {
            if (seats[i]) cnt.push_back(0);
            else {
                if (i>0) {
                    cnt.push_back(cnt[i-1]+1);
                } else {
                    cnt.push_back(len);
                }
            }
        }
        int ans = 0;
        for (int i = len-1; i >= 0; --i) {
            if (seats[i]) {
                cnt[i] = 0;
            } else {
                if (i != len-1) {
                    cnt[i] = min(cnt[i], cnt[i+1]+1);
                }
            }
            ans = max(ans, cnt[i]);
        }
        return ans;
    }
    // two pointer
    int maxDistToClosest2(vector<int>& seats) {
        int len = seats.size();
        int prev = -1, future = 0;
        int ans = 0;
        while (true) {
            while (true) {
                if (future >= len || seats[future] == 1) break;
                else future++;
            }
            for (int i = prev+1; i < future; ++i) {
                if (prev == -1) {
                    ans = max(ans, future-i);
                } else if (future >= len) {
                    ans = max(ans, i-prev);
                } else {
                    ans = max(ans, min(i-prev, future-i));
                }
            }
            if (future >= len) break;
            prev = future;
            future++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> seats;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        seats.push_back(x);
    }
    cout << s.maxDistToClosest(seats);
    return 0;
}
/**
7
1 0 0 0 1 0 1
*/
