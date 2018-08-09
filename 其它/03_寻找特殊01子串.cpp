/**
有一个数组，其中的元素只有0跟1，现在需要寻找这样一种子串（连续的），该子串中包含0的个数与1的个数是相等的，求最长子串的长度。

解：
将子串中的0变成-1，定义一个sum变量，开始遍历，sum从第一个元素一直累加到当前指针所指向的元素i，在累加的过程中，如果sum没有在hash表中出现过，
那么将该sum作为key，i作为value插入到hash table中。如果sum在hash表中出现过，并且当前的指针为j，也就是说在[i+1, j]的区间中，所有元素相加等于0，
这意味着这个区间内-1与1的个数相等，也就是0与1的个数相等，我们把区间长度记录下来，维护一个最长的值，就是最终的结果，这样时间复杂度为O(n)。
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
int hashtable[maxn];
int arr[1000];
int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (arr[i] == 0)
                arr[i] = -1;
        }
        memset(hashtable, 0, sizeof(hashtable));
        int sum = 0;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            sum += arr[i];
            if (hashtable[sum+n] == 0) { // 因为sum可能会得到负数，所以对于所有的值应该加上n保证结果为正数，这样才能作为下标
                hashtable[sum+n] = i;
            } else {
                res = max(res, i - hashtable[sum+n]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
/**
5
0 0 1 1 0
4

6
0 1 0 0 0 1
2

3
0 0 0
0
*/
