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
    map<RandomListNode*,RandomListNode*> dict;
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        
        map<RandomListNode*,RandomListNode*>::iterator it;
        it  = dict.find(head);
        if(it!=dict.end()){
            return dict[head];
        }
        
        RandomListNode* node = new RandomListNode(head->label);
        dict[head] = node;
        
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        
        return node;
    }
};
