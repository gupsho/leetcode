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

    ListNode* reverse(ListNode** head)
    {
        ListNode* first = (*head);
        if(first == NULL || first->next == NULL)
            return first;
        
        ListNode* second, *third;
        second = first;
        third = second->next;
        first = NULL;
        while(third != NULL)
        {
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        return second;
        
    }
    
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        ListNode* temp = head;
        int size = 0;
        while(temp!= NULL)
        {
            temp = temp->next;
            size++;
        }
        int mid = (size+1)/2;
        temp = head;
        while(mid > 1)
        {
            temp = temp->next;
            mid--;
        }
        
        ListNode* second = temp->next;
        second = reverse(&second);
        temp->next = NULL;
        
        while(second != NULL)
        {
            temp = head->next;
            head->next = second;
            second = second->next;
            head = head->next;
            head->next = temp;
            head = head->next;
        }
        
    }
};
