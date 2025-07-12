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
    bool checkL(int& rootval,TreeNode* subroot){
        if(subroot==nullptr){
            return true;
        }
        return (subroot->val<rootval) && checkL(rootval,subroot->left) && checkL(rootval,subroot->right);
    }
    bool checkR(int& rootval,TreeNode* subroot){
        if(subroot==nullptr){
            return true;
        }
        return (subroot->val>rootval) && checkR(rootval,subroot->left) && checkR(rootval,subroot->right);
    }
    bool check(TreeNode* root,long max,long min){
        if(root==nullptr){
            return true;
        }

        return (root->val>min && root->val<max) && check(root->left,root->val,min) && check(root->right,max,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        // if(root==nullptr){
        //     return true;
        // }
        // return checkL(root->val,root->left) && checkR(root->val,root->right) && isValidBST(root->left) && isValidBST(root->right);

        return check(root,LONG_MAX,LONG_MIN);


        // if (!root) {
        //     return true;
        // }

        // queue<tuple<TreeNode*, long, long>> queue;
        // queue.push(make_tuple(root, LONG_MIN, LONG_MAX));
        // while (!queue.empty()) {
        //     auto [node, left, right] = queue.front();
        //     queue.pop();

        //     if (!(left < node->val && node->val < right)) {
        //         return false;
        //     }
        //     if (node->left) {
        //         queue.push(make_tuple(node->left, left, node->val));
        //     }
        //     if (node->right) {
        //         queue.push(make_tuple(node->right, node->val, right));
        //     }
        // }
        // return true;
    }
};