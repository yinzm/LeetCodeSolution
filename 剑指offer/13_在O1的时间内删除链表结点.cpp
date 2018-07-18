#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    void deleteNode(ListNode** pHead, ListNode* pToBeDeleted) {
        if (pHead == NULL || pToBeDeleted == NULL) return ;
        // 正常结点
        if (pToBeDeleted->next != NULL) {
            ListNode *pNode = pToBeDeleted->next;
            pToBeDeleted->val = pNode->val;
            pToBeDeleted->next = pNode->next;
            delete pNode;
        } else if (*pHead == pToBeDeleted) { // 只有一个头结点
            delete *pToBeDeleted;
            *pHead = NULL;
        } else { // 被删除的节点是尾结点
            ListNode* pNode = *pHead;
            while (pNode->next != pToBeDeleted) {
                pNode = pNode->next;
            }
            pNode->next = NULL;
            delete pToBeDeleted;
        }
    }
};

int main() {

    return 0;
}
