#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k >= nums.size()) k %= nums.size();
        if (k <= 0) return;
        int p = 0, q = nums.size()-k-1;
        for (int i = p, j = q; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        p = q+1;
        q = nums.size()-1;
        for (int i = p, j = q; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        for (int i = 0, j = nums.size()-1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        return ;
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
    s.rotate(nums, k);
    for (auto x: nums) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
/**
7 3
1 2 3 4 5 6 7
5 6 7 1 2 3 4

3 0
1 2 3
1 2 3

3 3
1 2 3
1 2 3

2 3
1 2
2 1
*/
