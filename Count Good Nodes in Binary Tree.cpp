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
    void dfs(TreeNode* root,int max,int& count){
        if(root==nullptr){
            return ;
        }
        if(root->val>=max){
            count++;
        }
        max=std::max(max,root->val);
        dfs(root->left,max,count);
        dfs(root->right,max,count);
    }
public:
    int goodNodes(TreeNode* root) {
        // int res = 0;
        // queue<pair<TreeNode*, int>> q;
        // q.push({root, -INT_MAX});
        // while (!q.empty()) {
        //     auto [node, maxval] = q.front();
        //     q.pop();
        //     if (node->val >= maxval) {
        //         res++;
        //     }
        //     if (node->left) {
        //         q.push({node->left, max(maxval, node->val)});
        //     }
        //     if (node->right) {
        //         q.push({node->right, max(maxval, node->val)});
        //     }
        // }
        // return res;



        int max=root->val;
        int count=0;
        dfs(root,max,count);
        return count;
    }
};