#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tip: temp is not reference
    void check(vector<vector<int>>& res, vector<int> temp) {
        sort(temp.begin(), temp.end());
        if (res.size() == 0) {
            res.push_back(temp);
            return ;
        }
        bool dup = false;
        for (auto vec: res) {
            bool flag = true;
            for (int i = 0; i < vec.size(); ++i) {
                if (temp[i] != vec[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dup = true;
                break;
            }
        }
        if (!dup) res.push_back(temp);
    }
    void dfs(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& temp, int start, int sum) {
        if (temp.size() == 4) {
            if (sum == target) {
                check(res, temp);
            }
            return ;
        }
        if (start >= nums.size()) return ;
        for (int i = start; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            dfs(nums, target, res, temp, i+1, sum+nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, target, res, temp, 0, 0);
        return res;
    }
};

class Solution2 {
public:
    void check(vector<vector<int>>& res, vector<int>& temp) {
        sort(temp.begin(), temp.end());
        if (res.size() == 0) {
            res.push_back(temp);
            return ;
        }
        bool dup = false;
        for (auto vec: res) {
            bool flag = true;
            for (int i = 0; i < vec.size(); ++i) {
                if (temp[i] != vec[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dup = true;
                break;
            }
        }
        if (!dup) res.push_back(temp);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len-3; ++i) {
            for (int j = i+1; j < len-2; ++j) {
                int third = j+1, fourth = len-1;
                while (third < fourth) {
                    int val = nums[i]+nums[j]+nums[third]+nums[fourth];
                    if (val < target) {
                        third++;
                    } else if (val > target) {
                        fourth--;
                    } else {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[third]);
                        temp.push_back(nums[fourth]);
                        check(res, temp);
                        third++;
                        fourth--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    while (true) {
        Solution2 s;
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        vector<vector<int>> res = s.fourSum(nums, target);
        for (auto vec: res) {
            for (auto x: vec) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/**
6 0
1 0 -1 0 -2 2
[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
