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
    int inorder(TreeNode* root,int& k){
        if(root==nullptr){
            return 0;
        }
        int res=inorder(root->left,k);
        k--;
        if(k==0){
            res+=root->val;
            return res;
        }
        res+=inorder(root->right,k);
        return res;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // can also solve by storing values in inorder traversal
        // can also done by iterative inorder traversal without extra space

        // int k1=k;
        // return inorder(root,k1);



        // TreeNode* curr = root;
        // while (curr) {
        //     if (!curr->left) {
        //         k--;
        //         if (k == 0) return curr->val;
        //         curr = curr->right;
        //     } else {
        //         TreeNode* pred = curr->left;
        //         while (pred->right && pred->right != curr)
        //             pred = pred->right;
                
        //         if (!pred->right) {
        //             pred->right = curr;
        //             curr = curr->left;
        //         } else {
        //             pred->right = nullptr;
        //             k--;
        //             if (k == 0) return curr->val;
        //             curr = curr->right;
        //         }
        //     }
        // }
        // return -1;


        stack<TreeNode*> stack;
        TreeNode* curr = root;
        while (!stack.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1; 
    }
};