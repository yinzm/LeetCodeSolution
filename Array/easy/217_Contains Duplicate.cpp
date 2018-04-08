#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>myMap;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (myMap.find(nums[i]) != myMap.end()) {
                return true;
            } else {
                myMap[nums[i]] = 1;
            }
        }
        return false;
    }
    // clean code
    bool containsDuplicate2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if ((unique(nums.begin(), nums.end())) != nums.end()) {
            return true;
        } else {
            return false;
        }
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
