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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* temp = head;
        while (temp->next->next != nullptr) {
            ListNode* ptr = new ListNode(__gcd(temp->val, temp->next->val));
            ListNode* t = temp->next;
            ptr->next=t;
            temp->next=ptr;
            temp=temp->next->next;
            if(temp!=nullptr) cout<<temp->val<<endl;
        }
        if (temp->next->next == nullptr) {
            ListNode* ptr = new ListNode(__gcd(temp->val, temp->next->val));
            ListNode* t = temp->next;
            ptr->next=t;
            temp->next=ptr;
        }
        return head;
    }
};