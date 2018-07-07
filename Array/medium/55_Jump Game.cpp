#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        bool vis[len];
        memset(vis, false, sizeof(vis));
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int top = q.front(); q.pop();
            if (top == len-1) return true;
            for (int i = 1; i <= nums[top]; ++i) {
                int next = top+i;
                if (next >= len-1) {
                    return true;
                }
                if (!vis[next]) {
                    q.push(next);
                    vis[next] = true;
                }
            }
        }
        return false;
    }
    // brilliant idea
    bool canJump(vector<int>& nums) {
        int max_length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_length < i) return false;
            if (max_length >= nums.size()-1) return true;
            max_length = max(max_length, i+nums[i]);
        }
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << s.canJump(nums) << endl;
    return 0;
}
