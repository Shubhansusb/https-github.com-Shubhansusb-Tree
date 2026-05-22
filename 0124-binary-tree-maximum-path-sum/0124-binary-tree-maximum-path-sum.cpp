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
    int maxSum(TreeNode* root, int &sum){ //return the maxSum
        if(!root){
            return 0;
        }
        int leftTree = maxSum(root -> left, sum); //return maxSum in the leftTree
        int rightTree = maxSum(root -> right, sum);

        leftTree = max(0, leftTree); 
        rightTree = max(0, rightTree);
        sum = max(sum, leftTree + rightTree + root->val);// globally updating for everynode

        return max(leftTree, rightTree) + root -> val; //return this to parent node
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum ;
    }
};