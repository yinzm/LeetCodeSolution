#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int left1, int right1, vector<int>& inorder, int left2, int right2) {
        if (left1 > right1 || left2 > right2) return NULL;
        int root_val = preorder[left1];
        int pos_inorder = left2;
        for (int i = left2; i <= right2; ++i) {
            if (inorder[i] == root_val) {
                pos_inorder = i;
                break;
            }
        }
        int lson_cnt = pos_inorder - left2;
        int rson_cnt = right2 - pos_inorder;
        TreeNode *root = new TreeNode(root_val);
        root->left = build(preorder, left1+1, left1+lson_cnt, inorder, left2, pos_inorder-1);
        root->right = build(preorder, left1+lson_cnt+1, right1, inorder, pos_inorder+1, right2);
        return root;
    }
};

int main() {
    return 0;
}
