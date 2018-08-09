/**
对于普通的二叉树来说，每个节点只有指向自己左右儿子的指针，所以这个时候需要用递归的方法来实现。
如果对于一个节点root，要找的两个节点uv都在自己的左子树中，那么uv的公共祖先肯定位于root的左子树，递归下去。
如果uv都在自己的右子树中，那么公共祖先肯定位于root的右子树，递归下去。
如果uv一个在左子树，一个在右子树，那么肯定root就是最近公共祖先。
整个解题思路就是一个找节点在什么子树中的过程。
参考博客：
1. https://blog.csdn.net/xyzbaihaiping/article/details/52122885
2. https://blog.csdn.net/YoungLeoo/article/details/47953069

还有些其他的二叉树找公共祖先的情况，可以思考一下，上述博客中也有介绍。
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *lson, *rson;
    Node(int x): val(x), lson(NULL), rson(NULL){}
};

Node *getLastCommonAncestor(Node *root, Node *nodeU, Node *nodeV) {
    if (root == NULL) return NULL;
    if (root == nodeU || root == nodeV) return root;
    Node *lson = getLastCommonAncestor(root->lson, nodeU, nodeV);
    Node *rson = getLastCommonAncestor(root->rson, nodeU, nodeV);
    if (lson != NULL && rson != NULL) return root;
    else if (lson != NULL) return lson;
    else if (rson != NULL) return rson;
    else return NULL;
}

int main() {
    Node *root = new Node(1);
    Node *cur = root;
    queue<Node*>q;
    q.push(root);
    for (int i = 2; i <= 10; ++i) {
        if (!q.empty()) {
            Node *top = q.front();
            if (cur == top->lson) {
                cur = new Node(i);
                top->rson = cur;
                q.pop();
            } else {
                cur = new Node(i);
                top->lson = cur;
            }
            q.push(cur);
        }
    }
    Node *nodeU = root->lson->rson->lson; // 10
    Node *nodeV = root->lson->lson->rson; // 9
    Node *ancestor = getLastCommonAncestor(root, nodeU, nodeV);
    cout << nodeU->val << " and " << nodeV->val << " last common ancestor is " << ancestor->val << endl;
    return 0;
}
/**
                    1
                   / \
                  2   3
                / \   / \
               4  5  6   7
              /\  /
             8  9 10
*/
