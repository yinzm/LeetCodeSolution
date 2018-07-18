#include <bits/stdc++.h>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if (pHead == NULL) return NULL;
        map<RandomListNode*, RandomListNode*> pair_node;
        RandomListNode* root = copyAlongNext(pHead, pair_node);
        copyAlongRandom(pHead, root, pair_node);
        return root;
    }
    RandomListNode* copyAlongNext(RandomListNode* pnode,
                                  map<RandomListNode*, RandomListNode*>& pair_node) {
        RandomListNode *root = new RandomListNode(pnode->label);
        RandomListNode *p = root;
        pair_node[pnode] = root;
        while (pnode->next) {
            RandomListNode *node = new RandomListNode(pnode->next->label);
            pair_node[pnode->next] = node;
            p->next = node;
            p = p->next;
            pnode = pnode->next;
        }
        return root;
    }
    void copyAlongRandom(RandomListNode* pnode, RandomListNode* p,
                         map<RandomListNode*, RandomListNode*>& pair_node) {
        while (pnode) {
            RandomListNode *node = pair_node[pnode->random];
            p->random = node;
            p = p->next;
            pnode = pnode->next;
        }
    }
};

// better solution!
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        ConcatNode(pHead);
        MatchRandom(pHead);
        return SeperateList(pHead);
    }
    // 将所有新建的节点拼接到原节点后面
    void ConcatNode(RandomListNode* pHead) {
        if (pHead == NULL) return ;
        RandomListNode *p = pHead;
        while (p) {
            RandomListNode *pnode = new RandomListNode(p->label);
            pnode->next = p->next;
            p->next = pnode;
            p = pnode->next;
        }
    }
    // 将所有的random进行匹配
    void MatchRandom(RandomListNode* pHead) {
        if (pHead == NULL) return;
        RandomListNode *pnode = pHead;
        while (pnode) {
            RandomListNode *p = pnode->next;
            if (pnode->random) {
                p->random = pnode->random->next;
            }
            pnode = p->next;
        }
    }
    // 将两个链表分开
    RandomListNode* SeperateList(RandomListNode* pHead) {
        if (pHead == NULL) return NULL;
        RandomListNode *pnode = pHead;
        RandomListNode *root = pnode->next;
        while (pnode) {
            RandomListNode *p = pnode->next;
            pnode->next = p->next;
            pnode = pnode->next;
            if (pnode)
                p->next = pnode->next;
        }
        return root;
    }
};

int main() {
    return 0;
}
