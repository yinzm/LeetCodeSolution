#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0, len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i%2 == 0) {
                sum += nums[i];
            }
        }
        return sum;
    }
    // faster solution: bucket sort O(n)
    int arrayPairSum2(vector<int>& nums) {
        vector<int> bucket(20005); // default initialization, contains 20005 zeros
        size_t len = nums.size();
        for (size_t i = 0; i < len; ++i) {
            bucket[nums[i]+10000]++;
        }
        bool flag = true;
        size_t bucketLen = bucket.size();
        int sum = 0;
        for (size_t i = 0; i < bucketLen;) {
            if (bucket[i]) {
                if (flag) {
                    sum += (i-10000);
                    flag = false;
                } else {
                    flag = true;
                }
                --bucket[i];
            } else {
                ++i;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    int n, x;
    while (cin >> n) {
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            nums.push_back(x);
        }
        cout << s.arrayPairSum2(nums) << endl;
    }
    return 0;
}
