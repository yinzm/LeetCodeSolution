#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() == 0 || popV.size() == 0) return false;
        stack<int> s;
        int push_idx = 0, pop_idx = 0;
        while (true) {
            s.push(pushV[push_idx]);
            if (pushV[push_idx] == popV[pop_idx]) {
                pop_idx++;
                s.pop();
            }
            push_idx++;
            if (push_idx >= pushV.size() || pop_idx >= popV.size()) break;
        }
        if (push_idx < pushV.size()) return false;
        while (!s.empty() && pop_idx < popV.size()) {
            int val = s.top(); s.pop();
            if (val != popV[pop_idx]) return false;
            pop_idx++;
        }
        if (!s.empty()) return false;
        return true;
    }
    bool IsPopOrder2(vector<int> pushV, vector<int> popV) {
        if (pushV.size() == 0) return false;
        stack<int> s;
        for (int i = 0, j = 0; i < pushV.size(); ++i) {
            s.push(pushV[i]);
            while (j < popV.size() && s.top() == popV[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

int main() {
    return 0;
}
