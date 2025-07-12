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
    void dfs(TreeNode* root,vector<int>& ans,int level){
        if(root==nullptr){
            return;
        }
        if(ans.size()==level){
            ans.push_back(root->val);
        }
        dfs(root->right,ans,level+1);
        dfs(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> ans;
        // dfs(root,ans,0);
        // return ans;


        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* parent;
        int len;
        vector<int> ans;
        while(!q.empty()){
            len=q.size();
            while(len--){
                parent=q.front();
                q.pop();
                if(len==0){
                    ans.push_back(parent->val);
                }
                if(parent->left!=nullptr){
                    q.push(parent->left);
                }
                if(parent->right!=nullptr){
                    q.push(parent->right);
                }
            }
        }
        return ans;
    }
};