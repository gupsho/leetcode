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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        int num = temp->val;
        temp = temp->next;
        while(temp && temp->val == num)
            temp = temp->next;

        if(temp == head->next)
            temp = head;
        else if(temp == NULL || temp->next == NULL)
            return temp;
            
        if(temp->val == temp->next->val)
            return deleteDuplicates(temp);
        else {
            temp->next = deleteDuplicates(temp->next);
            return temp;
        }
    }
};
