#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num_set = 1 << nums.size();
        vector<vector<int>> res(num_set, vector<int>());
        for (int i = 1; i < num_set; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if ((i>>j) & 1) {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
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
    vector<vector<int>> res = s.subsets(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
