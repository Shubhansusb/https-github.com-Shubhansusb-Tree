class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        int leftToRight = true;
        queue<TreeNode*> q;
        if (!root)
            return answer;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                level.push_back(node->val);
            }
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }
            answer.push_back(level);
            leftToRight = !leftToRight;
        }

        return answer;
    }
};