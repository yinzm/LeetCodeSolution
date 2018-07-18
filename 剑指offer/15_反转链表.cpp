#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        ListNode *pNode = pHead;
        ListNode *pReverseHead = pHead;
        ListNode *pPrev = NULL;
        while (pNode != NULL) {
            ListNode *pNext = pNode->next;
            if (pNext == NULL) {
                pReverseHead = pNode;
            }
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }
};

int main() {
    return 0;
}
