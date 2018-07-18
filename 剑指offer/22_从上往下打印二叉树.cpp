#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front(); que.pop();
            res.push_back(node->val);
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
