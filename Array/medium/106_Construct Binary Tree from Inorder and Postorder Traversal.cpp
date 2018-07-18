#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder, int left1, int right1, vector<int>& postorder, int left2, int right2) {
        if (left1 > right1 || left2 > right2) return NULL;
        int root_val = postorder[right2];
        int pos_inorder = left1;
        for (int i = left1; i <= right1; ++i) {
            if (root_val == inorder[i]) {
                pos_inorder = i;
                break;
            }
        }
        int lson_cnt = pos_inorder - left1;
        int rson_cnt = right1 - pos_inorder;
        TreeNode *root = new TreeNode(root_val);
        root->left = build(inorder, left1, pos_inorder-1, postorder, left2, left2+lson_cnt-1);
        root->right = build(inorder, pos_inorder+1, right1, postorder, left2+lson_cnt, right2-1);
        return root;
    }
};

int main() {
    return 0;
}
