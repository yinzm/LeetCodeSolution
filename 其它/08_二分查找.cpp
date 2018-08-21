#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
int n;

int binarySearch(int L, int R, int target) {
    int mid = L+(R-L)/2;
    while (L < R) {
        if (nums[mid] >= target) {
            R = mid;
        } else {
            L = mid+1;
        }
        mid = L+(R-L)/2;
    }
    return R;
}

int main() {
    while (cin >> n) {
        int temp;
        nums.clear();
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            nums.push_back(temp);
        }
        int target;
        cin >> target;
        cout << binarySearch(0, nums.size(), target) << endl;
    }
    return 0;
}
/**
3
1 5 9
1
0

3
1 5 9
9
2

3
1 5 9
10
3

3
1 5 9
0
0

3
1 5 9
4
1

3
1 5 9
5
1
*/
