#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void push(int value) {
        if (number.empty()) {
            _min = value;
        } else {
            _min = _min > value ? value : _min;
        }
        number.push(value);
        min_num.push(_min);
    }
    void pop() {
        number.pop();
        _min = min_num.top();
        min_num.pop();
    }
    int top() {
        return number.top();
    }
    int min() {
        return min_num.top();
    }
private:
    stack<int> min_num;
    stack<int> number;
    int _min;
};

int main() {
    Solution s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.push(3);
    cout << s.min() << endl;
    cout << s.top() << endl;
    return 0;
}
