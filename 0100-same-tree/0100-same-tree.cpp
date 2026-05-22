class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q && !p) return true;
        if(!q || !p) return false;

        bool ans = (p -> val == q -> val) && isSameTree(p -> left, q-> left) && isSameTree(p-> right, q->right);
        return ans;
    }
};