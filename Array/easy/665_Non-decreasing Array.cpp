#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = 0, q = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                p = i;
                q = i+1;
                break;
            }
        }
        if (p == 0 && q == 0) return true;
        bool ok = true;
        int temp = nums[p];
        nums[p] = p == 0? INT_MIN : nums[p-1];
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                ok = false;
                break;
            }
        }
        nums[p] = temp;
        if (ok) return true;
        nums[q] = q == 0? INT_MIN : nums[q-1];
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                return false;
            }
        }
        return true;
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
    cout << s.checkPossibility(nums);
    return 0;
}
