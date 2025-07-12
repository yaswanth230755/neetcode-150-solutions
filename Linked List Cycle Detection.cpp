/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // unordered_set<ListNode*> seen;
        // ListNode* cur = head;
        // while (cur) {
        //     if (seen.find(cur) != seen.end()) {
        //         return true;
        //     }
        //     seen.insert(cur);
        //     cur = cur->next;
        // }
        // return false;


        ListNode *fast=head,*slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};