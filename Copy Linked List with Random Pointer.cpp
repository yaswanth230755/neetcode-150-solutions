/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // can also do without unordered_map

        // if (head == nullptr) {
        //     return nullptr;
        // }
        // Node* l1 = head;
        // while (l1 != nullptr) {
        //     Node* l2 = new Node(l1->val);
        //     l2->next = l1->next;
        //     l1->next = l2;
        //     l1 = l2->next;
        // }
        // Node* newHead = head->next;

        // l1 = head;
        // while (l1 != nullptr) {
        //     if (l1->random != nullptr) {
        //         l1->next->random = l1->random->next;
        //     }
        //     l1 = l1->next->next;
        // }
        // l1 = head;
        // while (l1 != nullptr) {
        //     Node* l2 = l1->next;
        //     l1->next = l2->next;
        //     if (l2->next != nullptr) {
        //         l2->next = l2->next->next;
        //     }
        //     l1 = l1->next;
        // }
        // return newHead;


        // below hashmap code can be done in one pass

        if(head==NULL)
            return NULL;
        unordered_map<Node*,Node*> unmap;
        Node *temp1=head;
        while(temp1){
            unmap[temp1]=new Node(temp1->val);
            temp1=temp1->next;
        }
        temp1=head;
        Node *ans=unmap[temp1],*temp2=ans;
        //if(temp1->random)
            temp2->random=unmap[temp1->random];
        temp1=temp1->next;
        while(temp1){
            temp2->next=unmap[temp1];
            temp2=temp2->next;
            //if(temp1->random)
                temp2->random=unmap[temp1->random];
            temp1=temp1->next;
        }
        return ans;
    }
};