#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> my_map;
        vector<int> ans;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int val = target-nums[i];
            if (my_map.find(val) != my_map.end()) {
                ans.push_back(i);
                ans.push_back(my_map[val]);
                return ans;
            } else {
                my_map[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int target, n, x;
    cin >> target;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans = s.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
/**
9
4
2 7 11 15
*/
