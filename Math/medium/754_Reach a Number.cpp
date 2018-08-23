/**
解析：
https://www.cnblogs.com/grandyang/p/8456022.html
https://leetcode.com/problems/reach-a-number/solution/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target>0) {
            k++;
            target -= k;
        }
        return target%2==0? k: k+1+k%2;
    }
};

int main() {
    Solution s;
    int target;
    while (cin >> target) {
        cout << s.reachNumber(target) << endl;
    }
    return 0;
}
