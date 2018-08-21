#include <bits/stdc++.h>
using namespace std;

class HeapSort {
public:
    void sortFunc(vector<int> &nums) {
        int len = nums.size();
        for (int i = len/2 - 1; i >= 0; --i) {
            adjustHeap(nums, i, len);
        }
        while (len > 1) {
            swapEle(&nums[0], &nums[len-1]);
            len--;
            adjustHeap(nums, 0, len);
        }
    }
    void adjustHeap(vector<int> &nums, int p, int len) {
        int temp = nums[p];
        for (int lson = p*2+1; lson < len; lson = lson*2+1) {
            int rson = lson+1;
            if (rson < len && nums[lson] < nums[rson]) { // 挑最大的元素进行处理，这样的话只需要处理一侧就行了，这里不需要交换，最后再交换即可。
                lson = rson;
            }
            if (nums[lson] > temp) {
                nums[p] = nums[lson];
                p = lson;
            } else {
                break;
            }
        }
        nums[p] = temp;
    }
    void swapEle(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        HeapSort heapSort;
        heapSort.sortFunc(nums);
        for (auto x: nums) {
            cout << x << " ";
        }cout << endl;
    }
    return 0;
}
/**
5
1 3 2 1 5

5
1 2 3 1 4

4
4 2 3 1
*/
