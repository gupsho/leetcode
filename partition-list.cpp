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
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* partitioned = head, *temp = head, *less = NULL, *more = NULL, *lessCurrent = NULL, *moreCurrent = NULL;
        if(head->val < x)
        {
            less = head;
            head = head->next;
            less->next = NULL;
            lessCurrent = less;
        }
        else
        {
            more = head;
            head = head->next;
            more->next = NULL;
            moreCurrent = more;
        }
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                if(less)
                {
                    lessCurrent->next = head;
                    head = head->next;
                    lessCurrent = lessCurrent->next;
                    lessCurrent->next = NULL;
                }
                else
                {
                    less = head;
                    head = head->next;
                    less->next = NULL;
                    lessCurrent = less;
                }
            }
            else
            {
                if(more)
                {
                    moreCurrent->next = head;
                    head = head->next;
                    moreCurrent = moreCurrent->next;
                    moreCurrent->next = NULL;
                }
                else
                {
                    more = head;
                    head = head->next;
                    more->next = NULL;
                    moreCurrent = more;
                }
            }
        }
        if(lessCurrent)
            lessCurrent->next = more;
        
        partitioned = (less == NULL)? more : less;
        return partitioned;
        
    }
};
