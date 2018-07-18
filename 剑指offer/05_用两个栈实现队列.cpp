#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void push(int node) {
        while (!stack1.empty()) {
            int val = stack1.top();
            stack1.pop();
            stack2.push(val);
        }
        stack2.push(node);
    }

    int pop() {
        while (!stack2.empty()) {
            int val = stack2.top();
            stack2.pop();
            stack1.push(val);
        }
        int ret = stack1.top();
        stack1.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    return 0;
}
