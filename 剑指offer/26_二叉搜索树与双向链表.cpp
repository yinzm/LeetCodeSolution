#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) return NULL;
        TreeNode *lastNodeInList = NULL;
        ConvertNode(pRootOfTree, &lastNodeInList);
        while (lastNodeInList && lastNodeInList->left) {
            lastNodeInList = lastNodeInList->left;
        }
        return lastNodeInList;
    }
    void ConvertNode (TreeNode* pnode, TreeNode** lastNodeInList) {
        if (pnode == NULL) return ;
        if (pnode->left) {
            ConvertNode(pnode->left, lastNodeInList);
        }
        pnode->left = *lastNodeInList;
        if (*lastNodeInList) // important
            (*lastNodeInList)->right = pnode;
        *lastNodeInList = pnode;
        if (pnode->right) {
            ConvertNode(pnode->right, lastNodeInList);
        }
    }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) return NULL;
        TreeNode *lastNodeInList = NULL;
        ConvertNode(pRootOfTree, lastNodeInList);
        while (lastNodeInList && lastNodeInList->left) {
            lastNodeInList = lastNodeInList->left;
        }
        return lastNodeInList;
    }
    void ConvertNode (TreeNode* pnode, TreeNode* &lastNodeInList) {
        if (pnode == NULL) return ;
        if (pnode->left) {
            ConvertNode(pnode->left, lastNodeInList);
        }
        pnode->left = lastNodeInList;
        if (lastNodeInList) // important
            lastNodeInList->right = pnode;
        lastNodeInList = pnode;
        if (pnode->right) {
            ConvertNode(pnode->right, lastNodeInList);
        }
    }
};

int main() {
    return 0;
}
