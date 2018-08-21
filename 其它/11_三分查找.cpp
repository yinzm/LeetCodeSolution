// https://blog.csdn.net/littlewhite520/article/details/70144763
#include <bits/stdc++.h>
using namespace std;

// 找最大
void sanfenSearch(vector<int> &nums) {
    int left = 0, right = nums.size()-1;
    while (left < right-1) {
        int mid = left+(right-left)/2;
        int mmid = mid+(right-mid)/2;
        if (nums[mid] >= nums[mmid]) {
            right = mmid;
        } else {
            left = mid;
        }
    }
    int res = nums[left] >= nums[right] ? nums[left] : nums[right];
    cout << res << endl;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        sanfenSearch(nums);
    }
    return 0;
}
/**
5
1 2 3 2 1

6
1 1 1 3 1 1
*/
