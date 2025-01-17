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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5002); 
        ListNode* temp = dummy;
        dummy->next = head;
        if(head == nullptr) return nullptr;
        int i=0;
        while(temp!=nullptr && temp->next!=nullptr){
           if(temp->val > temp->next->val){
            ListNode* key = temp->next;
            ListNode* prev = dummy;
            ListNode* ptr = dummy->next;
            while(ptr!=nullptr && ptr->val <= key->val){
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = key;
            temp->next = key->next;
            key->next = ptr;
            if(i==0){
                cout<<temp->val<<endl;
            }
            i++;
            // cout<<dummy->val<<endl;
            // cout<<dummy->next->val<<endl;
            // cout<<dummy->next->next->val<<endl;
            // cout<<dummy->next->next->next->val<<endl;
            // cout<<dummy->next->next->next->next->val<<endl;
            // cout<<temp->next<<endl;
           }
           else if(temp!=nullptr) temp=temp->next;
        }
       return dummy->next;
    }
};