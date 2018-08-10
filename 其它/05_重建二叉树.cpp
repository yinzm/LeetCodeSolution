#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *lson, *rson;
    Node(int x):val(x), lson(NULL), rson(NULL){}
};
Node* constructBinaryTreeCore(vector<int>& pre, int left1, int right1, vector<int> &in, int left2, int right2) {
    if (left1 > right1 || left2 > right2) return NULL;
    Node *root = new Node(pre[left1]);
    int pos = -1;
    for (int i = left2; i <= right2; ++i) {
        if (in[i] == pre[left1]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return NULL;
    int lson_cnt = pos-left2;
    root->lson = constructBinaryTreeCore(pre, left1+1, left1+lson_cnt, in, left2, pos-1);
    root->rson = constructBinaryTreeCore(pre, left1+lson_cnt+1, right1, in, pos+1, right2);
    return root;
}

Node* reConstructBinaryTree(vector<int>& pre, vector<int> &in) {
    return constructBinaryTreeCore(pre, 0, pre.size()-1, in, 0, in.size()-1);
}

void postOrderTraverse(Node *root) {
    if (root == NULL) return ;
    postOrderTraverse(root->lson);
    postOrderTraverse(root->rson);
    cout << root->val << " ";
}

int main() {
    vector<int> pre={1,2,4,3,5,7,6};
    vector<int> in ={2,4,1,5,7,3,6};
    Node *root = reConstructBinaryTree(pre, in);
    cout << "post order traverse:" << endl;
    postOrderTraverse(root);
    cout << endl;
    return 0;
}
/**
post order traverse:
4 2 7 5 6 3 1
*/
