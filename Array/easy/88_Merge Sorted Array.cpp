#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i<m) {
            ans.push_back(nums1[i++]);
        }
        while (j<n) {
            ans.push_back(nums2[j++]);
        }
        nums1.clear();
        for (int i = 0; i < ans.size(); ++i) {
            nums1.push_back(ans[i]);
        }
    }
    // brilliant idea!!
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        while (i>=0 && j>=0) {
            if (nums1[i]>=nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j>=0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1, nums2;
    int m, n;
    cin >> m >> n;
    int x;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        nums1.push_back(x);
    }
    for (int j = 0; j < n; ++j) {
        cin >> x;
        nums2.push_back(x);
    }
    s.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
