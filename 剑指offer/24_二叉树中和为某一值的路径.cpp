#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<int> temp;
        dfs(res, temp, root, expectNumber, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& temp, TreeNode* node, int expectNumber, int sum) {
        if (node == NULL) return ;
        temp.push_back(node->val);
        if (node->left == NULL && node->right == NULL) {
            if (sum + node->val == expectNumber) {
                res.push_back(temp);
            }
        }
        dfs(res, temp, node->left, expectNumber, sum+node->val);
        dfs(res, temp, node->right, expectNumber, sum+node->val);
        temp.pop_back();
    }
};

int main() {
    return 0;
}
