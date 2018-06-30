#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // neat code
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        int cnt = 0, max_edge = 0;
        for (int i = 0; i < len; ++i) {
            max_edge = max(max_edge, arr[i]);
            if (max_edge == i) cnt++;
        }
        return cnt;
    }
    int maxChunksToSorted2(vector<int>& arr) {
        int len = arr.size();
        int p = 0, q = 0;
        int cnt = 0;
        while (true) {
            int i = p;
            while (i <= q) {
                if (arr[i] > q) q = arr[i];
                i++;
            }
            cnt++;
            q++;
            p = q;
            if (q >= len) break;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> arr;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        arr.push_back(x);
    }
    cout << s.maxChunksToSorted(arr);
    return 0;
}
/**
5
4 3 2 1 0

5
1 0 2 3 4
*/
