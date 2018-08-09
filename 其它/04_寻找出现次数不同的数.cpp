/**
第一题：
有一个数组，每个数字都出现2次，但是只有一个数字他是出现一次的，请找到这个数字。
解：
使用异或操作

第二题：
有一个数组，每个数字都出现2次，但是只有两个数字是只出现一次的，请找到这两个数字。
解：
1.使用异或操作得到一个值val
2.然后看val的二进制表示中，从右往左的第一位1的位置，假如第二位是1，这个1肯定是因为那两个独特的数字在该位取值不同而产生的
3.将所有的数字都右移一位，然后将第一位为1的归为一个集合中，第一位为0的归为一个集合中，然后两个集合都转为了第一题，同样的方法求解
这个解法的巧妙之处在于，利用异或操作的性质，找到了区分两个不同数字的点。
*/
#include <bits/stdc++.h>
using namespace std;


int firstSolution(int *arr, int n) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res ^= arr[i];
    }
    return res;
}

void secondSolution(int *arr, int m, int &a, int &b) {
    int res = firstSolution(arr, m);
    int pos = 0;
    for (int i = 0; ; ++i) {
        if (res&1) {
            pos = i;
            break;
        } else {
            res >>= 1;
        }
    }
    a = 0, b = 0;
    for (int i = 0; i < m; ++i) {
        int val = arr[i]>>pos;
        if (val&1) {
            a ^= arr[i];
        } else {
            b ^= arr[i];
        }
    }
}

int main() {
    int n, m;
    int arr[100];
    while (cin >> n) {
        // 第一题
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << firstSolution(arr, n) << endl;
        cout << "input second question: m" << endl;
        cin >> m;
        // 第二题
        for (int i = 0; i < m; ++i) {
            cin >> arr[i];
        }
        int a, b;
        secondSolution(arr, m, a, b);
        cout << a << " " << b << endl;
    }
    return 0;
}
/**
7
1 1 2 3 2 4 4
3
input second question: m
6
1 2 3 4 1 2
3 4
*/
