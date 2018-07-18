#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        while (head != NULL) {
            s.push(head->val);
            head = head->next;
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
    void printListFromTailToHead2(ListNode* head) {
        if (head == NULL) {
            return ;
        }
        printListFromTailToHead2(head->next);
        cout << head->val << " ";
    }
};

int main() {
    ListNode *head = NULL;
    ListNode *p = head;
    for (int i = 1; i <= 10; ++i) {
        ListNode *node = new ListNode(i);
        if (i == 1) {
            head = node;
            p = head;
        } else {
            p->next = node;
            p = p->next;
        }
    }
    Solution s;
    vector<int> ans = s.printListFromTailToHead(head);
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    s.printListFromTailToHead2(head);
    return 0;
}
