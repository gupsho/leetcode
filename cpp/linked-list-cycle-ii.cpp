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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        ListNode *slow = head, *fast=head->next;
        while(slow!=fast && slow!=NULL && fast!=NULL)
        {
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                return NULL;
        }
        if(slow != fast)
            return NULL;
        
        fast = slow->next;
        int length = 1;
        while(fast!= slow)
        {
            fast = fast->next;
            length++;
        }
        
        slow = head;
        fast = head;
        
        while(length)
        {
            fast = fast ->next;
            length--;
        }
        
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
