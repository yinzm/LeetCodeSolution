#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, numPointer = 0;
        while (zeroPointer < nums.size() && numPointer < nums.size()) {
            while (zeroPointer < nums.size() && nums[zeroPointer] != 0) {
                zeroPointer++;
            }
            while (numPointer < nums.size() && nums[numPointer] == 0) {
                numPointer++;
            }
            if (zeroPointer < nums.size() && numPointer < nums.size()) {
                if (numPointer > zeroPointer) {
                    swap(nums[zeroPointer], nums[numPointer]);
                } else {
                    numPointer++;
                }
            }
        }
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
    s.moveZeroes(nums);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
