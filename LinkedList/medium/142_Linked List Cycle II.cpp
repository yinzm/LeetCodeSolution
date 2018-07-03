#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pslow = head, *pfast = head;
        while (pslow!=NULL && pfast!=NULL && pfast->next!=NULL) {
            pslow = pslow->next;
            pfast = pfast->next->next;
            if (pslow == pfast) {
                pslow = head;
                while (pslow != pfast) {
                    pslow = pslow->next;
                    pfast = pfast->next;
                }
                return pslow;
            }
        }
        return NULL;
    }
};

int main() {
    Solution s;
    ListNode *head = NULL;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        ListNode node(x);
        ListNode *p;
        if (i == 0) {
            head = &node;
            p = head;
        } else {
            p->next = &node;
            p = p->next;
        }
    }
    ListNode *ans = s.detectCycle(head);
    cout << ans->val << endl;
    return 0;
}
