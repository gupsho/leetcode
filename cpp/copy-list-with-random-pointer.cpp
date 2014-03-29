/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* copy;
        RandomListNode* orig, *copied;
        
        orig = head;
        //Insert new nodes in between original list
        while(orig != NULL)
        {
            RandomListNode* node = new RandomListNode(orig->label);
            node->next = orig->next;
            orig->next = node;
            orig = node->next;
        }
        
        orig = head;
        //Copy random pointer
        while(orig != NULL)
        {
            copied = orig->next;
            if(orig->random)
                copied->random = orig->random->next;
            orig = copied->next;
        }
        
        orig = head;
        copy = orig->next;
        //Separate the lists
        while(orig != NULL)
        {
            copied = orig->next;
            orig->next = copied->next;
            if(orig->next)
                copied->next = orig->next->next;
            orig = orig->next;
        }
        
        return copy;
    }
};
