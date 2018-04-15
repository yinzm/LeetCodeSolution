#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int len = nums.size();
        int bucket[50010];
        memset(bucket, 0, sizeof(bucket));
        int degree = 0;
        for (int i = 0; i < len; ++i) {
            bucket[nums[i]]++;
            degree = max(degree, bucket[nums[i]]);
        }
        int p1 = 0, p2 = 0;
        int min_dist = len;
        memset(bucket, 0, sizeof(bucket));
        bucket[nums[p2]] = 1;
        while (p2 < len) {
            if (bucket[nums[p2]] == degree) {
                min_dist = min(min_dist, p2-p1+1);
                bucket[nums[p1]]--;
                p1++;
            } else {
                p2++;
                if (p2 >= len) {
                    break;
                }
                bucket[nums[p2]]++;
            }
        }
        return min_dist;
    }
    // 更加好理解的解法
    int findShortestSubArray2(vector<int>& nums) {
        int len = nums.size();
        int bucket[50010];
        int left[50010];
        int right[50010];
        int degree = 0, min_dist = len;
        memset(bucket, 0, sizeof(bucket));
        memset(left, -1, sizeof(left));
        memset(right, -1, sizeof(right));
        for (int i = 0; i < len; ++i) {
            bucket[nums[i]]++;
            degree = max(degree, bucket[nums[i]]);
            if (left[nums[i]] == -1) {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
        }
        for (int i = 0; i < len; ++i) {
            if (bucket[nums[i]] == degree) {
                min_dist = min(min_dist, right[nums[i]] - left[nums[i]] + 1);
            }
        }
        return min_dist;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.findShortestSubArray(nums) << endl;
    return 0;
}
/*
5
1 2 2 3 1
7
1 2 2 3 1 4 2
*/
