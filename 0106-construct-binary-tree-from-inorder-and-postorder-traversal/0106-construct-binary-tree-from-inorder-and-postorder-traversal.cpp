/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int find(vector<int>& inorder, int element) {
        for (int i = 0; i < inorder.size(); i++) {
            if (element == inorder[i])
                return i;
        }

        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index,
                    int inorderStart, int inorderEnd, int n) {
        if (index < 0 || inorderStart > inorderEnd)
            return nullptr;

        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        // findpos in inorder
        int position = find(inorder, element);
        root->right =
            solve(inorder, postorder, index, position + 1, inorderEnd, n);
        root->left =
            solve(inorder, postorder, index, inorderStart, position - 1, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        int index = size - 1;
        return solve(inorder, postorder, index, 0, size - 1, size);
    }
};