#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() <= 0) return 0;
        int res = array[0];
        int sum = res;
        for (int i = 1; i < array.size(); ++i) {
            sum = max(array[i], array[i]+sum);
            res = max(res, sum);
        }
        return res;
    }
};

int main() {
    return 0;
}
