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
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* head = l1;
        ListNode* other = l2;
        
        if (l1->val > l2->val)
        {
            head = l2;
            other = l1;
        }
        
        while (head->next && other)
        {
            ListNode* next = head->next;
            
            if (other->val < next->val)
            {
                head->next = other;
                other = other->next;
                head->next->next = next;
            }
            else
                head = next;
        }
        
        if (other) head->next = other;
        return l1->val > l2->val ? l2 : l1;
    }
};