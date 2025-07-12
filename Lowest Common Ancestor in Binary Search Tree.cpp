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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* temp=root;
        int min=std::min(p->val,q->val);
        int max=std::max(p->val,q->val);
        while(root!=nullptr){
            // All Node.val are unique.
            if(root->val<min){
                root=root->right;
            }
            else if(root->val>max){
                root=root->left;
            }
            else{
                return root;
            }
        }
        return root;
    }
};