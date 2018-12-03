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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* node = new ListNode(l1->val);
        ListNode* nodehead = node;
        ListNode* pt1 = l1;
        ListNode* pt2 = l2;
        while(pt1 != NULL && pt2 != NULL){
            if(pt1->val < pt2->val){
                node->next = pt1;
                pt1 = pt1->next;
                node = node->next;
            }
            else if(pt1->val >= pt2->val){
                node->next = pt2;
                pt2 = pt2->next;
                node = node->next;
            }
        }
        if(pt1 == NULL)
            node->next = pt2;
        else if(pt2 == NULL)
            node->next = pt1;
        return nodehead->next;
    }
};
