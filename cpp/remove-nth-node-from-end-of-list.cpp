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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL)
            return head;
        
        ListNode* first = head;
        int count = 1;
        while(count <= n) {
            first = first->next;
            count++;
        }
        ListNode* second = head, *third = NULL;
        while(first != NULL) {
            first = first->next;
            third = second;
            second = second->next;
        }
        if(third == NULL) {
            return head->next;
        } else {
            third->next = second->next;
        }
        return head;
    }
};
