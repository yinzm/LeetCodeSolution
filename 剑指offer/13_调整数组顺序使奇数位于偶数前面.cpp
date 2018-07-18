#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        bool flag;
        int len = array.size();
        if (len <= 1) return ;
        for (int i = 0; i < len-1; ++i) {
            flag = false;
            for (int j = 0; j < len-1; ++j) {
                if ( !(array[j]&1) && (array[j+1]&1) ) {
                    swap(array[j], array[j+1]);
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }
        return ;
    }
    // 插入排序思想
    void reOrderArray2(vector<int> &array) {
        int len = array.size();
        if (len <= 1) return ;
        int pOdd = 0, pEven = 0;
        while (true) {
            while (array[pEven]&1)pEven++;
            bool flag = false;
            for (pOdd = pEven+1; pOdd < len; ++pOdd) {
                if (array[pOdd]&1) {
                    flag = true;
                    break;
                }
            }
            if (!flag) break;
            int temp = array[pOdd];
            for (int i = pOdd; i > pEven; --i) {
                array[i] = array[i-1];
            }
            array[pEven] = temp;
        }
        return ;
    }
};

int main() {
    while (true) {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        Solution s;
        s.reOrderArray2(array);
        for (int i = 0; i < n; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
5
1 2 3 4 5

3
1 1 2
*/
