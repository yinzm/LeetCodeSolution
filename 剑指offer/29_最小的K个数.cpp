#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, less<int> > que; // 大顶堆
        vector<int> res;
        if (input.size() <= 0 || k <= 0 || input.size() < k) return res;
        for (int i = 0; i < k; ++i) {
            que.push(input[i]);
        }
        for (int i = k; i < input.size(); ++i) {
            int val = que.top();
            if (input[i] < val) {
                que.pop();
                que.push(input[i]);
            }
        }
        while (!que.empty()) {
            res.push_back(que.top());
            que.pop();
        }
        vector<int> res2;
        for (vector<int>::iterator it = res.end()-1; it >= res.begin(); it--) {
            res2.push_back(*it);
        }
        return res2;
    }
};

class Solution2 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size() <= 0 || k <= 0 || input.size() < k) return res;
        int left = 0, right = input.size()-1;
        int index = Partition(input, left, right);
        int key = k-1;
        while (index != key) {
            if (index > key) {
                index = Partition(input, left, index-1);
            } else {
                index = Partition(input, index+1, right);
            }
        }
        for (int i = 0; i <= index; ++i) {
            res.push_back(input[i]);
        }
        return res;
    }
    int Partition(vector<int>& input, int left, int right) {
        if (left == right) return left;
        int key = input[left];
        int i = left, j = right;
        while (i < j) {
            while (i < j && input[j] >= key)j--;
            while (i < j && input[i] <= key)i++;
            swap(input[i], input[j]);
        }
        input[left] = input[i];
        input[i] = key;
        return i;
    }
};

int main() {
    Solution2 s;
    int n, k;
    while (cin >> n >> k) {
        vector<int> input(n);
        for (int i = 0; i < n; ++i) {
            cin >> input[i];
        }
        vector<int> res = s.GetLeastNumbers_Solution(input, k);
        for (auto x: res) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
/**
8 4
4 5 1 6 2 7 3 8
1 2 3 4
*/
