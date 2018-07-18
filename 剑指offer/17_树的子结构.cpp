#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL) return false;
        bool flag = false;
        if (pRoot1->val == pRoot2->val) {
            flag = isContains(pRoot1, pRoot2);
        }
        if (!flag) {
            flag = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!flag) {
            flag = HasSubtree(pRoot1->right, pRoot2);
        }
        return flag;
    }
    bool isContains(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot2 == NULL) return true;
        if (pRoot1 == NULL) return false;
        if (pRoot1->val != pRoot2->val) return false;
        return isContains(pRoot1->left, pRoot2->left) &&
               isContains(pRoot1->right, pRoot2->right);
    }
};

int main() {
    return 0;
}
