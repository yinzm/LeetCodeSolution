#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int idx = i+1;
            if (nums[i] != idx) {
                while (true) {
                    int swapIdx = nums[i]-1;
                    if (nums[swapIdx] != (swapIdx+1)) {
                        swap(nums[i], nums[swapIdx]);
                    } else {
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != (i+1)) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
    // smart idea and clean code !!!
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int idx = abs(nums[i])-1;
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }
        vector<int> ans;
        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    int n, x;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans = s.findDisappearedNumbers2(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
