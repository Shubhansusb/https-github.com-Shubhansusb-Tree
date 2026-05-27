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
    int widthOfBinaryTree(TreeNode* root) {
       unsigned long long int maxWidth = 0;
        if (!root)
            return maxWidth;

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            int size = q.size();
            auto [left,leftExtreme]  = q.front();
            auto [right,rightExtreme] = q.back();
            maxWidth = max(maxWidth,-leftExtreme+rightExtreme+1);
            for(int i =0; i<size; i++){
                auto [node, m] = q.front();
                q.pop();
                if (node->left)
                    q.push({node->left, 2 * m + 1});
                if (node->right)
                    q.push({node->right, 2 * m + 2});
            }
        }
        return maxWidth;
    }
};