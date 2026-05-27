/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParents(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parentsMap) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                parentsMap[node->left] = node;
            }

            if (node->right) {
                q.push(node->right);
                parentsMap[node->right] = node;
            }
        }
    }
    void find(TreeNode* root, int k,
              unordered_map<TreeNode*, TreeNode*>& parentsMap, int curr,
              vector<int> &answer, unordered_set<TreeNode*> visited) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        visited.insert(root);
        while (!q.empty()) {
            auto [node, c] = q.front();
            q.pop();
            if (c == k)
                answer.push_back(node->val);
            if (node->left && !visited.contains(node->left)) {
                q.push({node->left, c + 1});
                visited.insert(node->left);
            }
            if (node->right && !visited.contains(node->right)) {
                q.push({node->right, c + 1});
                visited.insert(node->right);
            }
            if (parentsMap[node] && !visited.contains(parentsMap[node])) {
                q.push({parentsMap[node], c + 1});
                visited.insert(parentsMap[node]);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentsMap;
        unordered_set<TreeNode*> visited;
        vector<int> answer;
        mapParents(root, parentsMap);
        find(target, k, parentsMap, 0, answer, visited);
        return answer;
    }
};