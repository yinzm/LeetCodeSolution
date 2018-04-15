#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int ans1 = nums[len-1]*nums[len-2]*nums[len-3];
        int ans2 = nums[0]*nums[1]*nums[len-1];
        return max(ans1, ans2);
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.maximumProduct(nums) << endl;
    return 0;
}
