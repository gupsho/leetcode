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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* sorted, *temp;
        if(head == NULL || head->next == NULL)
            return head;
        sorted = head;
        temp = sorted;
        head = head->next;
        temp->next = NULL;
        while(head != NULL)
        {
            if(head->val >= temp->val)
            {
                temp->next = head;
                temp = temp->next;
                head = head->next;
                temp->next = NULL;
            }
            else if(head->val < sorted->val)
            {
                ListNode* current = head;
                head = head->next;
                current->next = sorted;
                temp->next = NULL;
                sorted = current;
            }
            else
            {
                temp = sorted;
                while(temp->next->val < head->val)
                    temp = temp->next;
                ListNode* nextNode = temp->next;
                temp->next = head;
                head = head->next;
                temp = temp->next;
                temp->next = nextNode;
                while(temp->next != NULL)
                    temp = temp->next;
            }
        }
        temp->next = NULL;
        return sorted;
    }
};
