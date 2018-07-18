#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return false;
        if (nums.size() == 1) return nums[0] == target? true: false;
        int pos = findStartPoint(nums);
        if (pos > 0 && target >= nums[0]) {
            return binarySearch(nums, target, 0, pos);
        } else {
            return binarySearch(nums, target, pos, nums.size());
        }
    }
    bool binarySearch(vector<int>& nums, int target, int left, int right) {
        int mid = left+(right-left)/2;
        while (left < right) {
            if (nums[mid] >= target) {
                if (nums[mid] == target) return true;
                right = mid;
            } else {
                left = mid+1;
            }
            mid = left+(right-left)/2;
        }
        return nums[right] == target ? true: false;
    }
    int findStartPoint(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int mid = left+(right-left)/2;
        int index = 0;
        while (nums[left] >= nums[right]) {
            if (left+1 == right) {
                index = right;
                break;
            }
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                index = orderSearch(left, right, nums);
                break;
            }
            if (nums[mid] >= nums[left]) {
                left = mid;
            } else if (nums[mid] <= nums[right]) {
                right = mid;
            }
            mid = left+(right-left)/2;
        }
        return index;
    }
    int orderSearch(int l, int r, vector<int>& nums) {
        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < nums[i-1]) {
                return i;
            }
        }
        return l;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C++-solution-(o(logn)-on-average-o(n)-worst-case)
class Solution2 {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid = (left+right)>>1;
        while (left <= right) {
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }
            if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            mid = (left+right)>>1;
        }
        return false;
    }
};
int main() {
    Solution s;
    int n, target;
    while (cin >> n >> target) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << s.search(nums, target) << endl;
    }
    return 0;
}
/**
4 5
2 3 4 1

5 3
1 3 1 1 1
*/
