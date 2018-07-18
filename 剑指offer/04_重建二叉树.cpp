#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, int left1, int right1, vector<int>& vin, int left2, int right2) {
        if (left1 > right1 || left2 > right2) return NULL;
        TreeNode *head = new TreeNode(pre[left1]);
        int i = left2, cnt = 0;
        for (; i <= right2; ++i) {
            if (pre[left1] == vin[i]) {
                break;
            }
            cnt++;
        }
        head->left = buildTree(pre, left1+1, left1+cnt, vin, left2, i-1);
        head->right = buildTree(pre, left1+cnt+1, right1, vin, i+1, right2);
        return head;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return buildTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
};

int main() {

}
