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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* H = new ListNode(0);
        H -> next = head;
        ListNode* first = H;
        ListNode* second = H;
        for(int i=0;i<n;i++)
        {
            first = first->next;
        }
        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return H->next;
    }
};
