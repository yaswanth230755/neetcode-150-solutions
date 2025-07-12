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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if (!l1) return l2;
        // if (!l2) return l1;
        // int carry = 0, sum;
        // ListNode* ans = new ListNode();
        // ListNode* temp = ans;
        // while (l1 || l2 || carry) {
        //     int val1 = l1 ? l1->val : 0;
        //     int val2 = l2 ? l2->val : 0;
        //     sum = val1 + val2 + carry;
        //     carry = sum / 10;
        //     temp->next = new ListNode(sum % 10);
        //     temp = temp->next;
        //     if (l1) l1 = l1->next;
        //     if (l2) l2 = l2->next;
        // }
        // return ans->next;



        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        int carry=0,sum;
        ListNode *ans,*temp;
        sum=l1->val+l2->val;
        carry=sum/10;
        ans=new ListNode(sum%10);
        temp=ans;
        l1=l1->next;
        l2=l2->next;
        while(l1!=nullptr && l2!=nullptr){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        if(carry){
            if(l1!=nullptr){
                temp->next=addTwoNumbers(new ListNode(carry),l1);
            }
            else{
                temp->next=addTwoNumbers(new ListNode(carry),l2);
            }
        }
        else{
            if(l1!=nullptr){
                temp->next=l1;
            }
            else{
                temp->next=l2;
            }
        }
        return ans;
    }
};