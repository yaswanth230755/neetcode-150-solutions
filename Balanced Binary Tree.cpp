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
    int height(TreeNode* root) {
        // can be done bfs or dfs

        // if(root==NULL){
        //     return -1;
        // }
        // int maxL=height(root->left)+1;
        // int maxR=height(root->right)+1;
        // return (maxL>=maxR)?maxL:maxR;
        if(root==NULL){
            return -1;
        }
        int level=-1,no_of_nodes_in_level;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            no_of_nodes_in_level=q.size();
            for(int i=0;i<no_of_nodes_in_level;i++){
                if(q.front()->left!=NULL)
                q.push(q.front()->left);
                if(q.front()->right!=NULL)
                q.push(q.front()->right);
                q.pop();
            }
            level++;
        }
        return level;

    }


    int check(TreeNode* root,bool& flag){
        if(root==nullptr){
            return -1;
        }
        if(flag){
        int heightL=check(root->left,flag);
        int heightR=check(root->right,flag);
        if(abs(heightL-heightR)>1){
            flag=false;
        }
        return max(heightL,heightR)+1;
        }
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // if(root==NULL)
        // return true;
        // if(abs(height(root->left)-height(root->right))<2)
        //     return isBalanced(root->left) && isBalanced(root->right);
        // return false;


        bool flag=true;
        check(root,flag);
        return flag;


        // stack<TreeNode*> stack;
        // TreeNode* node = root;
        // TreeNode* last = nullptr;
        // unordered_map<TreeNode*, int> depths;

        // while (!stack.empty() || node != nullptr) {
        //     if (node != nullptr) {
        //         stack.push(node);
        //         node = node->left;
        //     } else {
        //         node = stack.top();
        //         if (node->right == nullptr || last == node->right) {
        //             stack.pop();
        //             int left = depths[node->left];
        //             int right = depths[node->right];
        //             if (abs(left - right) > 1) return false;
        //             depths[node] = 1 + max(left, right);
        //             last = node;
        //             node = nullptr;
        //         } else {
        //             node = node->right;
        //         }
        //     }
        // }
        // return true;
    }
};
