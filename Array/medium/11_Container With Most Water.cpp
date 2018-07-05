#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int max_area = (right-left)*min(height[left], height[right]);
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            int area = (right-left)*min(height[left], height[right]);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    cout << s.maxArea(height);
    return 0;
}
/**
3
1 2 3

*/
