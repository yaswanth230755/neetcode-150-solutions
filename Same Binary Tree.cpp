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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // stack<pair<TreeNode*, TreeNode*>> stk;
        // stk.push({p, q});
        // while (!stk.empty()) {
        //     auto [node1, node2] = stk.top();
        //     stk.pop();
        //     if (!node1 && !node2) continue;
        //     if (!node1 || !node2 || node1->val != node2->val) return false;
        //     stk.push({node1->right, node2->right});
        //     stk.push({node1->left, node2->left});
        // }
        // return true;



        if(p==nullptr || q==nullptr){
            return (p==nullptr && q==nullptr);
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && (p->val==q->val);


        // if(p==NULL && q==NULL)
        //     return true;
        // if(p==NULL || q==NULL)
        //     return false;
        // queue<TreeNode*> q1,q2;
        // q1.push(p);
        // q2.push(q);
        // while(!q1.empty() && !q2.empty()){
        //     if(q1.front()->val!=q2.front()->val)
        //         return false;
        //     if(q1.front()->left!=NULL && q2.front()->left!=NULL){
        //         q1.push(q1.front()->left);
        //         q2.push(q2.front()->left);
        //     }
        //     else if(q1.front()->left!=NULL || q2.front()->left!=NULL){
        //         return false;
        //     }
        //     if(q1.front()->right!=NULL && q2.front()->right!=NULL){
        //         q1.push(q1.front()->right);
        //         q2.push(q2.front()->right);
        //     }
        //     else if(q1.front()->right!=NULL || q2.front()->right!=NULL){
        //         return false;
        //     }
        //     q1.pop();
        //     q2.pop();
        // }
        // if(q1.empty() && q2.empty())
        //     return true;
        // return false;
    }
};