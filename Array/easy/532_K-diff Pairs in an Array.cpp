#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        set<int> myset, ans;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k == 0) {
                if (myset.find(nums[i]) != myset.end()) {
                    if (ans.find(nums[i]) == ans.end()) {
                        cnt++;
                        ans.insert(nums[i]);
                    }
                } else {
                    myset.insert(nums[i]);
                }
            } else {
                if (myset.find(nums[i]) != myset.end()) continue;
                int bigger = nums[i] + k;
                int smaller = nums[i] - k;
                if (myset.find(bigger) != myset.end()) {
                    cnt++;
                }
                if (myset.find(smaller) != myset.end()) {
                    cnt++;
                }
                myset.insert(nums[i]);
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << s.findPairs(nums, k);
    return 0;
}
/**
5 2
3 1 4 1 5
2

5 1
1 2 3 4 5
4

5 0
1 3 1 5 4
1

3 0
1 1 1
1
*/
