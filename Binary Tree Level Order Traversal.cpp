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
    void dfs(TreeNode* node, int depth,vector<vector<int>>& res) {
        if (!node) return;
        
        if (res.size() == depth) {
            res.push_back(vector<int>());
        }
        
        res[depth].push_back(node->val);
        dfs(node->left, depth + 1,res);
        dfs(node->right, depth + 1,res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // vector<vector<int>> res;
        // dfs(root, 0,res);
        // return res;


        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* parent;
        int len;
        vector<vector<int>> ans;
        vector<int> v;
        while(!q.empty()){
            len=q.size();
            v={};
            while(len--){
                parent=q.front();
                q.pop();
                v.push_back(parent->val);
                if(parent->left!=nullptr){
                    q.push(parent->left);
                }
                if(parent->right!=nullptr){
                    q.push(parent->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};