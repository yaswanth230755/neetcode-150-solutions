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
    ListNode* reverseList(ListNode* head) {
    //      if (!head || !head->next) {
    //     return head;
    // }
    // ListNode* newHead = reverseList(head->next); // Step 1
    // head->next->next = head;                     // Step 2
    // head->next = nullptr;                        // Step 3
    // return newHead;


        ListNode* nex=NULL,*prev=NULL;
        while(head!=NULL){
            nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;
        }
        return prev;
    }
};
