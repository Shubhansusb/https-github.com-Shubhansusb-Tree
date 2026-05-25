class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(!root ->left && !root -> right) return true;
        else return false;
    }
    void solve(TreeNode* root, vector<string>& pathsToLeaf, string path) {
        if (!root)
            return;
        path += to_string(root->val);    

        if (isLeaf(root)) {
            pathsToLeaf.push_back(path);
            return;
        }
        path +="->";
        solve(root->left, pathsToLeaf, path);
        solve(root->right, pathsToLeaf, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> pathsToLeaf;
        solve(root, pathsToLeaf, "");

        return pathsToLeaf;
    }
};