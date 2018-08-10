// 三种遍历递归非递归版本的实现
// reference : https://blog.csdn.net/YoungLeoo/article/details/47952127
// reference : https://www.cnblogs.com/SHERO-Vae/p/5800363.html
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node *lson, *rson;
    Node (int x):val(x), lson(NULL), rson(NULL){}
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 递归版本
void preOrderTraverse(Node *root) {
    if (root == NULL) return ;
    cout << root->val << " ";
    preOrderTraverse(root->lson);
    preOrderTraverse(root->rson);
}
// 非递归版本
void preOrderTraverse2(Node *root) {
    stack<Node*>s;
    s.push(root);
    while (!s.empty()) {
        Node *cur = s.top(); s.pop();
        if (cur) {
            cout << cur->val << " ";
            s.push(cur->rson); // 注意这里，应该先将右儿子入栈，因为打印是反过来的
            s.push(cur->lson);
        }
    }
}
// 非递归版本2
void visitAlongLeftBranch(Node *x, stack<Node*> &s) {
    while (x) {
        cout << x->val << " ";
        if (x->rson) s.push(x->rson);
        x = x->lson;
    }
}
void preOrderTraverse3(Node *root) {
    stack<Node*> s;
    Node *cur = root;
    while (true) {
        visitAlongLeftBranch(cur, s);
        if (s.empty()) break;
        cur = s.top();
        s.pop();
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 递归版本
void inOrderTraverse(Node *root) {
    if (root==NULL) return;
    inOrderTraverse(root->lson);
    cout << root->val << " ";
    inOrderTraverse(root->rson);
}
// 非递归版本
void visitAlongLeftBranch2(Node *x, stack<Node*> &s) {
    while (x) {
        s.push(x);
        x = x->lson;
    }
}
void inOrderTraverse2(Node *root) {
    Node *cur = root;
    stack<Node*> s;
    while (true) {
        visitAlongLeftBranch2(cur, s);
        if (s.empty()) break;
        cur = s.top(); s.pop();
        cout << cur->val << " ";
        cur = cur->rson;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 递归版本
void postOrderTraverse(Node *root) {
    if (root==NULL) return;
    postOrderTraverse(root->lson);
    postOrderTraverse(root->rson);
    cout << root->val << " ";
}
// 非递归版本
void postOrderTraverse2(Node *root) {
    stack<Node*> s;
    s.push(root);
    Node *pre = NULL;
    while (!s.empty()) {
        Node *cur = s.top();
        if ((cur->lson == NULL && cur->rson == NULL ) ||
        (pre != NULL && (pre == cur->lson || pre == cur->rson))) {
            cout << cur->val << " ";
            pre = cur;
            s.pop();
        } else {
            if (cur->rson) {
                s.push(cur->rson);
            }
            if (cur->lson) {
                s.push(cur->lson);
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    Node *root = new Node(1);
    Node *cur = root;
    queue<Node*> q;
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
    cout << "preOrder Traverse:" << endl;
    cout << "method1: ";
    preOrderTraverse(root); cout << endl;
    cout << "method2: ";
    preOrderTraverse2(root); cout << endl;
    cout << "method3: ";
    preOrderTraverse3(root); cout << endl;
    cout << "==============================" << endl;
    cout << "inOrder Traverse:" << endl;
    cout << "method1: ";
    inOrderTraverse(root); cout << endl;
    cout << "method2: ";
    inOrderTraverse2(root); cout << endl;
    cout << "==============================" << endl;
    cout << "postOrder Traverse:" << endl;
    cout << "method1: ";
    postOrderTraverse(root); cout << endl;
    cout << "method2: ";
    postOrderTraverse2(root); cout << endl;
    return 0;
}
/**
                        1
                       / \
                      2    3
                     / \   /\
                    4   5 6  7
                   /\   /
                  8  9  10

preOrder :   1, 2, 4, 8, 9, 5, 10, 3, 6, 7
inOrder  :   8, 4, 9, 2, 10, 5, 1, 6, 3, 7
postOrder:   8, 9, 4, 10, 5, 2, 6, 7, 3, 1

*/
