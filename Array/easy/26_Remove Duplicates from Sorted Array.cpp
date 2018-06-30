#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }
        int pre = 0, next = 1;
        while (true) {
            while (next < len && nums[next] == nums[pre]) next++;
            if (next >= len) break;
            if (pre < next) {
                pre++;
                nums[pre] = nums[next];
            }
        }
        return pre+1;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    int ans = s.removeDuplicates(nums);
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
