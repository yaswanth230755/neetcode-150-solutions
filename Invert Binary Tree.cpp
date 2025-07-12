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
    TreeNode* invertTree(TreeNode* root) {
        // if(root==nullptr){
        //     return nullptr;
        // }
        // TreeNode *left=root->left,*right=root->right;
        // root->left=invertTree(right);
        // root->right=invertTree(left);
        // return root;


        //  if(root==nullptr){
        //     return nullptr;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // TreeNode* temp,*right,*left;
        // while(!q.empty()){
        //     temp=q.front();
        //     q.pop();
        //     left=temp->left;
        //     right=temp->right;
        //     temp->left=right;
        //     temp->right=left;
        //     if(left!=nullptr){
        //         q.push(left);
        //     }
        //     if(right!=nullptr){
        //         q.push(right);
        //     }
        // }
        // return root;


        if(root==nullptr){
            return nullptr;
        }
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* temp,*right,*left;
        while(!st.empty()){
            temp=st.top();
            st.pop();
            left=temp->left;
            right=temp->right;
            temp->left=right;
            temp->right=left;
            if(right!=nullptr){
                st.push(right);
            }
            if(left!=nullptr){
                st.push(left);
            }
        }
        return root;
    }
};