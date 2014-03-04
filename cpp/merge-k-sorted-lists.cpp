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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0)
            return NULL;
            
        if(lists.size() == 1)
            return lists[0];
            
        ListNode* mergedHead, *temp;
        int min_index = -1, min = INT_MAX;
        for(int i = 0; i<lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                if(lists[i]->val < min)
                {
                    min = lists[i]->val;
                    min_index = i;
                }
                    
            }
        }
        if(min_index == -1)
            return NULL;
        
        mergedHead = lists[min_index];
        lists[min_index] = lists[min_index]->next;
        temp = mergedHead;
        temp->next = NULL;
        
        bool allListsCovered = false;
        while(1)
        {
            min = INT_MAX;
            min_index = -1;
            allListsCovered = true;
            for(int i = 0; i<lists.size(); i++)
            {
                if(lists[i] != NULL)
                {
                    if(lists[i]->val < min)
                    {
                        min = lists[i]->val;
                        min_index = i;
                        allListsCovered = false;
                    }
                    
                }
            }
            if(allListsCovered)
                break;
            temp->next = lists[min_index];
            lists[min_index] = lists[min_index]->next;
            temp = temp->next;
        }
        temp->next = NULL;
        
        return mergedHead;
        
    }
};
