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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newHead = head->next, *previous = NULL;
        
        while(head && head->next)
        {
            ListNode* nextNode = head->next, *newNode = head->next->next;
            if(previous != NULL)
                previous->next = nextNode;
            nextNode->next = head;
            head->next = newNode;
            previous = head;
            head = newNode;
        }
        
        return newHead;
        
    }
};
