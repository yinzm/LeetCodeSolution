#include <bit/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> Q;
        Q.push(make_pair(root, 1));
        while (!Q.empty()) {
            pair<TreeNode*, int> pr = Q.front(); Q.pop();
            TreeNode *node = pr.first;
            int step = pr.second;
            if (node->left == nullptr && node->right == nullptr) {
                return step;
            }
            if (node->left) {
                Q.push(make_pair(node->left, step+1));
            }
            if (node->right) {
                Q.push(make_pair(node->right, step+1));
            }
        }
        return 0;
    }
};

int main() {

    return 0;
}
