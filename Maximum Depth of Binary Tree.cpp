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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        //return std::max(maxDepth(root->left),maxDepth(root->right))+1;

        queue<TreeNode*> q;
        q.push(root);
        int len,depth=0;
        TreeNode* temp;
        while(!q.empty()){
            len=q.size();
            while(len--){
                temp=q.front();
                q.pop();
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
            depth++;
        }
        return depth;
    }
};