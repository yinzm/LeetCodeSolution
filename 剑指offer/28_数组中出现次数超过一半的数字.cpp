#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() <= 0) return 0;
        int mid = numbers.size() >> 1;
        int left = 0, right = numbers.size()-1;
        int index = Partition(numbers, left, right);
        while (index != mid) {
            if (index > mid) {
                index = Partition(numbers, left, index-1);
            } else {
                index = Partition(numbers, index+1, right);
            }
        }
        int val = numbers[mid];
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == val) {
                cnt++;
            }
        }
        if (cnt*2 > numbers.size()) {
            return val;
        } else {
            return 0;
        }
        return 0;
    }
    int Partition(vector<int>& numbers, int left, int right) {
        if (left == right) return left;
        int key = numbers[left];
        int i = left, j = right;
        while (i < j) {
            while (j > i && numbers[j] >= key)j--;
            while (j > i && numbers[i] <= key)i++;
            swap(numbers[i], numbers[j]);
        }
        numbers[left] = numbers[i];
        numbers[i] = key;
        return i;
    }
};

class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() <= 0) return 0;
        int res = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (times == 0) {
                res = numbers[i];
                times = 1;
            } else if (numbers[i] != res) {
                times--;
            } else {
                times++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == res) {
                cnt++;
            }
        }
        if (cnt * 2 > numbers.size()) {
            return res;
        } else {
            return 0;
        }
    }
};

int main() {
    Solution2 s;
    int n;
    while (cin >> n) {
        vector<int> numbers(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }
        cout << s.MoreThanHalfNum_Solution(numbers) << endl;
    }
    return 0;
}
/**
9
1 2 3 2 2 2 5 4 2
*/
