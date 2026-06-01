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
    int findPos(int &element, vector<int>& in){
        for(int i=0; i< in.size(); i++){
            if(element == in[i]) return i;
        }

        return -1;
    }
    TreeNode* solve(vector<int>&pre, vector<int>&in, int &index, int inStart, int inEnd, int size){
        if(index >= size || inStart > inEnd) return nullptr;

        int element = pre[index++];
        TreeNode* root = new TreeNode(element);
        int position = findPos(element, in);
        root -> left = solve(pre, in, index, inStart, position-1, size);
        root -> right = solve(pre, in, index, position+1, inEnd, size);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int index = 0; int n = pre.size();
        return solve(pre, in, index, 0, n-1, n);
    }
};