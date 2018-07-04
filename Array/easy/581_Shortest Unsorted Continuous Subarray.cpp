#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int p = 0, q = nums.size()-1;
        while (nums[p] == temp[p]) p++;
        while (nums[q] == temp[q]) q--;
        if (p>=q) return 0;
        else return q-p+1;
    }
    // method 2
    int findUnsortedSubarray2(vector<int>& nums) {
        int bound1 = 0, bound2 = 0, _max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < _max) {
                if (bound1 == 0) bound1 = i;
                bound2 = i;
            } else {
                _max = nums[i];
            }
        }
        int inner_min = nums[bound1];
        for (int i = bound1; i <= bound2; ++i) {
            inner_min = min(inner_min, nums[i]);
        }
        for (int i = 0; i < bound1; ++i) {
            if (nums[i] > inner_min) {
                bound1 = min(bound1, i);
                break;
            }
        }
        if (bound1 >= bound2) return 0;
        else return bound2-bound1+1;
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
    cout << s.findUnsortedSubarray2(nums);
    return 0;
}
/**
7
2 6 4 8 10 9 15
5

5
1 3 5 4 2
4

5
2 5 3 1 4
5
*/
