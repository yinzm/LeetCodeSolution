#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stringstream ss;
        stack<int> oprand;
        for (auto x: tokens) {
            int a, b;
            if (x == "+") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b+a);
            } else if (x == "-") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b-a);
            } else if (x == "*") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b*a);
            } else if (x == "/") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b/a);
            } else {
                ss.clear();
                ss << x;
                int number;
                ss >> number;
                oprand.push(number);

            }
        }
        return oprand.top();
    }
    int evalRPN2(vector<string>& tokens) {
        stack<int> oprand;
        for (auto x: tokens) {
            int a, b;
            if (x == "+") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b+a);
            } else if (x == "-") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b-a);
            } else if (x == "*") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b*a);
            } else if (x == "/") {
                a = oprand.top(); oprand.pop();
                b = oprand.top(); oprand.pop();
                oprand.push(b/a);
            } else {
                int number = stoi(x);
                oprand.push(number);
            }
        }
        return oprand.top();
    }
};

int main() {
    Solution s;
    vector<string> tokens;
    string temp;
    while (cin >> temp) {
        tokens.push_back(temp);
    }
    cout << s.evalRPN2(tokens) << endl;
    return 0;
}
