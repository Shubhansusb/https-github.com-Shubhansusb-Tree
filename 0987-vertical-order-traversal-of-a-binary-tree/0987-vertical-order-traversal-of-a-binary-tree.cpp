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
    void getValueAndCoordinates(TreeNode* root, vector<tuple<int,int,int>>&valueAndCoordinates, int row, int col){
        if(!root) return;
        valueAndCoordinates.push_back(make_tuple(col,row, root -> val));
        getValueAndCoordinates(root -> left, valueAndCoordinates,row+1, col-1);
        getValueAndCoordinates(root -> right, valueAndCoordinates,row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>valueAndCoordinates;
        vector<vector<int>>answer;
        if(!root) return answer;
        getValueAndCoordinates(root, valueAndCoordinates,0,0);

        sort(valueAndCoordinates.begin(), valueAndCoordinates.end());

        int prevColumn = INT_MIN; 
        for( auto &[c,r,v] : valueAndCoordinates){
            if(c != prevColumn){
                answer.push_back({});
                prevColumn= c;
            }
            answer.back().push_back(v);
        }

        return answer;
    }
};