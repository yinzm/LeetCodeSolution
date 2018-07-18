#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return removeDuplicatesNum(nums, 2);
    }
    int removeDuplicatesNum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k) return len;
        int new_tail = 1, tail = 1;
        int cnt = 1;
        while (tail < len) {
            if (nums[tail] != nums[tail-1]) {
                cnt = 1;
                nums[new_tail] = nums[tail];
                new_tail++;
            } else {
                if (cnt < k) {
                    cnt++;
                    nums[new_tail] = nums[tail];
                    new_tail++;
                }
            }
            tail++;
        }
        return new_tail;
    }
    int removeDuplicatesNum(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < k) return len;
        int tail = 1, new_tail = 1;
        int cnt = 1;
        while (tail < len) {
            if (nums[tail] != nums[tail-1]) {
                cnt = 1;
                nums[new_tail] = nums[tail];
                new_tail++;
            } else {
                if (cnt < k) {
                    cnt++;
                    nums[new_tail] = nums[tail];
                    new_tail++;
                }
            }
            tail++;
        }
        return new_tail;
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << s.removeDuplicates(nums) << endl;
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
6
1 1 1 2 2 3
5

3
1 1 1
2

9
0 0 1 1 1 1 2 3 3
7

3
1 1 1
2
*/
