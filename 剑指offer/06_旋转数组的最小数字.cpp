#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOrder(vector<int>& rotateArray, int left, int right) {
        int res = rotateArray[left];
        for (int i = left+1; i <= right; ++i) {
            res = min(res, rotateArray[i]);
        }
        return res;
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0, right = rotateArray.size()-1;
        int mid = left+(right-left)/2;
        int res = left;
        while (rotateArray[left] >= rotateArray[right]) {
            if ((rotateArray[mid] == rotateArray[left])&&
                (rotateArray[mid] == rotateArray[right])){
                res = minOrder(rotateArray, left, right);
                break;
            }
            if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else if (rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
            if (right-left == 1) {
                res = rotateArray[right];
                break;
            }
            mid = left+(right-left)/2;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> rotateArray(n);
    for (int i = 0; i < n; ++i) {
        cin >> rotateArray[i];
    }
    Solution s;
    cout << s.minNumberInRotateArray(rotateArray);
    return 0;
}
/**
5
3 4 5 1 2
1

5
1 1 1 0 1
0

5
1 0 1 1 1
0
*/
