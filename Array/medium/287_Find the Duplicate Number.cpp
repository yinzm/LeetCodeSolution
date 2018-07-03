#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                int next_id = nums[i];
                while (nums[next_id] != next_id) {
                    swap(nums[i], nums[next_id]);
                    next_id = nums[i];
                }
                if (nums[i] != i) {
                    return nums[i];
                }
            }
        }
    }
    // 把题目转化为判断是否有环，如果有环，那么找到环的入口
    int findDuplicate2(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[ nums[fast] ];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
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
    cout << s.findDuplicate2(nums);
    return 0;
}
