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
     ListNode* rec(ListNode* root, ListNode* cur) {
        if (cur == nullptr) {
            return root;
        }

        root = rec(root, cur->next);
        if (root == nullptr) {
            return nullptr;
        }

        ListNode* tmp = nullptr;
        if (root == cur || root->next == cur) {
            cur->next = nullptr;
        } else {
            tmp = root->next;
            root->next = cur;
            cur->next = tmp;
        }

        return tmp;
    }
public:
    void reorderList(ListNode* head) {
        
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while (fast != nullptr && fast->next != nullptr) {
        //     slow = slow->next;
        //     fast = fast->next->next;
        // }
        // ListNode* second = slow->next;
        // ListNode* prev = slow->next = nullptr;
        // while (second != nullptr) {
        //     ListNode* tmp = second->next;
        //     second->next = prev;
        //     prev = second;
        //     second = tmp;
        // }
        // ListNode* first = head;
        // second = prev;
        // while (second != nullptr) {
        //     ListNode* tmp1 = first->next;
        //     ListNode* tmp2 = second->next;
        //     first->next = second;
        //     second->next = tmp1;
        //     first = tmp1;
        //     second = tmp2;
        // }


        //  head = rec(head, head->next);




        int j=0,i=0;
        ListNode* temp=head;
        vector<ListNode*> v;
        while(temp!=nullptr){
            v.emplace_back(temp);
            temp=temp->next;
            j++;
        }
        j--;
        while(j-i>1){
            temp=v[i]->next;
            v[i]->next=v[j];
            v[j-1]->next=v[j]->next;
            v[j]->next=temp;
            i++;
            j--;
        }
    }
};