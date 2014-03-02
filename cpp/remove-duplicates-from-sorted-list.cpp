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
        if(!head)
            return head;
        ListNode* iter = head;
        
        int num = head->val;
        while(iter->next) {
            if(iter->next->val == num) {
                ListNode* temp = iter->next;
                iter->next = iter->next->next;
                delete temp;
            } else {
                iter = iter->next;
                if(iter)
                    num = iter->val;
            }
        }
        return head;
    }
};
