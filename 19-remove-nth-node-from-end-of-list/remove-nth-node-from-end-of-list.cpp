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
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        if(cnt==n){
            ListNode* NewHead = head->next;
            delete(head);
            return NewHead;
        }

        ListNode* fast = head;
        for(int i=0; i<n; i++) fast = fast->next;
        ListNode* slow = head;
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* DelN = slow->next;
        slow->next = slow->next->next;
        delete(DelN);
        return head;
    }
};