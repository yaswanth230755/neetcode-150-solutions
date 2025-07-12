/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // can use by 2 times traversal and left and right pointer
        
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* left = dummy;
        // ListNode* right = head;

        // while (n > 0) {
        //     right = right->next;
        //     n--;
        // }

        // while (right != nullptr) {
        //     left = left->next;
        //     right = right->next;
        // }

        // left->next = left->next->next;
        // return dummy->next;



        // ListNode *temp=head,*par=nullptr;
        // int len=0;
        // while(temp!=nullptr && temp->next!=nullptr){
        //     temp=temp->next->next;
        //     len+=2;
        // }
        // if(temp!=nullptr){
        //     len++;
        // }
        // n=len-n;
        // temp=head;
        // while(n--){
        //     par=temp;
        //     temp=temp->next;
        // }
        // if(par!=nullptr){
        //     par->next=par->next->next;
        // }
        // else{
        //     head=head->next;
        // }
        // return head;



        ListNode* temp=head;
        queue<ListNode*> q;
        int i=0;
        while(temp!=NULL){
            if(q.size()==n+1){
                q.pop();
            }
            q.push(temp);
            temp=temp->next;
        }
        if(q.front()->next!=NULL && q.size()==n+1)
        q.front()->next=q.front()->next->next;
        if(q.size()<n+1)
        head=head->next;
        return head;
    }
};
