#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
            int toFind = target - numbers[i];
            int loc = binarySearch(numbers, toFind, i+1, len);
            if (loc != -1) {
                vector<int> index;
                index.push_back(i+1);
                index.push_back(loc+1);
                return index;
            }
        }
    }
    int binarySearch(vector<int>& numbers, int target, int l, int r) {
        int mid = l+(r-l)/2;
        while (l < r) {
            if (numbers[mid] >= target) {
                r = mid;
            } else {
                l = mid+1;
            }
            mid = l+(r-l)/2;
        }
        if (r >= 0 && r < numbers.size() && numbers[r] == target) {
            return r;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution s;
    vector<int> numbers;
    int n, x, target;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        numbers.push_back(x);
    }
    cin >> target;
    vector<int> index = s.twoSum(numbers, target);
    cout << index[0] << " " << index[1] << endl;
    return 0;
}
