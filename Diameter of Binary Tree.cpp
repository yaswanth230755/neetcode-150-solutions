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
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return -1;
        }
        return std::max(maxDepth(root->left),maxDepth(root->right))+1;

        // queue<TreeNode*> q;
        // q.push(root);
        // int len,depth=-1;
        // TreeNode* temp;
        // while(!q.empty()){
        //     len=q.size();
        //     while(len--){
        //         temp=q.front();
        //         q.pop();
        //         if(temp->left!=nullptr){
        //             q.push(temp->left);
        //         }
        //         if(temp->right!=nullptr){
        //             q.push(temp->right);
        //         }
        //     }
        //     depth++;
        // }
        // return depth;
    }

    int dfs(TreeNode* root,int& diameter){
        if(root==nullptr){
            return -1;
        }
        int heightR=dfs(root->right,diameter);
        int heightL=dfs(root->left,diameter);
        diameter=max(heightR+heightL+2,diameter);
        return max(heightR,heightL)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // if(root==nullptr){
        //     return 0;
        // }
        // return std::max(maxDepth(root->left)+maxDepth(root->right)+2,std::max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));

        int diameter=0;
        dfs(root,diameter);
        return diameter;


        // unordered_map<TreeNode*, pair<int, int>> mp;
        // mp[nullptr] = {0, 0};
        // stack<TreeNode*> stack;
        // stack.push(root);
        // while (!stack.empty()) {
        //     TreeNode* node = stack.top();
        //     if (node->left && mp.find(node->left) == mp.end()) {
        //         stack.push(node->left);
        //     } else if (node->right && mp.find(node->right) == mp.end()) {
        //         stack.push(node->right);
        //     } else {
        //         node = stack.top();
        //         stack.pop();
        //         auto[leftHeight, leftDiameter] = mp[node->left];
        //         auto[rightHeight, rightDiameter] = mp[node->right];
        //         int height = 1 + std::max(leftHeight, rightHeight);
        //         int diameter = max(leftHeight + rightHeight, 
        //                        max(leftDiameter, rightDiameter));
        //         mp[node] = {height, diameter};
        //     }
        // }
        // return mp[root].second;
    }
};