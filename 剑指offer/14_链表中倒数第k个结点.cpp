#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k <= 0) return NULL;
        ListNode *p1 = pListHead;
        ListNode *p2 = pListHead;
        int cnt = 0;
        while (true) {
            if (p2 != NULL) {
                p2 = p2->next;
                cnt++;
            } else {
                return NULL;
            }
            if (cnt >= k)break;
        }
        while (p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main() {
    return 0;
}
