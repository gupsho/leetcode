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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k < 1)
            return head;
        ListNode* first = head;
        int len = 0;
        while(first != NULL) {
            first = first->next;
            len++;
        }
        
        if(k % len == 0)
            return head;
        
        first = head;
        k = k % len;
        
        int count = 1;
        while(count <= k) {
            first = first->next;
            if(first == NULL)
                return head;
            count++;
        }
        
        ListNode* second = head, *third = NULL;
        while(first != NULL) {
            first = first->next;
            third = second;
            second = second->next;
        }
        
        if(second != head) {
            while(second->next != NULL)
                second = second->next;
            second->next = head;
            head = third->next;
            third->next = NULL;
        }
        
        return head;
        
    }
};
