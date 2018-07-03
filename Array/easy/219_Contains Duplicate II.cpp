#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> hashmap;
        for (int i = 0; i < len; ++i) {
            if (hashmap.find(nums[i]) == hashmap.end()) {
                hashmap[nums[i]] = i;
            } else {
                if (i - hashmap[nums[i]] <= k) {
                    return true;
                }
                hashmap[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int n, x;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    cout << s.containsNearbyDuplicate(nums);
    return 0;
}
