#include <bits/stdc++.h>
using namespace std;

void swapFunc(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(vector<int> &nums, int left, int right) {
    if (left >= right) {
        for (auto x: nums) {
            cout << x << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = left; i <= right; ++i) {
        swapFunc(&nums[i], &nums[left]);
        permutation(nums, left+1, right);
        swapFunc(&nums[i], &nums[left]);
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        permutation(nums, 0, nums.size()-1);
    }
    return 0;
}
/**
3
1 2 3
*/
