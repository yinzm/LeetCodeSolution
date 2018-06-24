#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        int p = 1;
        for (int i = 0; i < nums.size(); ++i) {
            out.push_back(p);
            p *= nums[i];
        }
        p = 1;
        for (int i = nums.size()-1; i >= 0; --i) {
            out[i] *= p;
            p *= nums[i];
        }
        return out;
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
    vector<int> out = s.productExceptSelf(nums);
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << " ";
    }
    cout << endl;
    return 0;
}
