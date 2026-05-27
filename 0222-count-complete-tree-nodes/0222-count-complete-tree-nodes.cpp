/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front(); 
            q.pop();
            ans++;

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        return ans;
    }
};