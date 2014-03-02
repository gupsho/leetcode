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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
            
        ListNode* l3, *head, *temp;
        int carry = 0;
        
        temp = new ListNode((l1->val + l2->val)%10);
        carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        l3 = temp;
        head = l3;
        
        while(l1 != NULL && l2 != NULL)
        {
            temp = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            l3->next = temp;
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        
        if(l1)
        {
            while(l1)
            {
                temp = new ListNode((l1->val + carry)%10);
                carry = (l1->val + carry)/10;
                l3->next = temp;
                l1 = l1->next;
                l3 = l3->next;
            }
        } 
        else if(l2)
        {
            while(l2)
            {
                temp = new ListNode((l2->val + carry)%10);
                carry = (l2->val + carry)/10;
                l3->next = temp;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        if(carry)
        {
            temp = new ListNode(carry);
            l3->next = temp;
            carry = 0;
        }
        
        return head;
    }
};
