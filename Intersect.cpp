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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *A = headA;
        ListNode *B = headB;
        while(A != NULL || B != NULL){
            while(A != NULL && B != NULL){
                if(A->val == B->val){
                    return A;
                }  
                A = A->next;
                B = B->next;
            }
            if(A == NULL && B == NULL){
                break;
            }
            else if(A == NULL){
                A = headB;
            }
            else if(B == NULL){
                B = headA;
            }
        }
        return NULL;
    }
};
