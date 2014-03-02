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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l2)
            return l1;
        if(!l1)
            return l2;
        
        ListNode *l3, *head;
        if(l1->val < l2->val)
        {
            l3 = l1;
            l1 = l1->next;
        }
        else
        {
            l3 = l2;
            l2 = l2->next;
        }
        head = l3;
        l3->next = NULL;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                l3->next = l1;
                l1 = l1->next;
            }
            else
            {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
            l3->next = NULL;
            
        }
        if(l2)
            l3->next = l2;
        else if(l1)
            l3->next = l1;
            
        return head;
        
    }
};
