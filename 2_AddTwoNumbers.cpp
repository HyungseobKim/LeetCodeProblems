/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* curr = head;
        
        while (l1 && l2)
        {
            curr->val += l1->val;
            curr->val += l2->val;
            
            if (l1->next || l2->next || curr->val >= 10)
            {
                curr->next = new ListNode(curr->val/10);
                curr->val = curr->val % 10;
            }
            
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1)
        {
            curr->val += l1->val;
            
            if (l1->next || curr->val >= 10)
            {
                curr->next = new ListNode(curr->val/10);
                curr->val = curr->val % 10;
            }
            
            curr = curr->next;
            l1 = l1->next;
        }
        
        while (l2)
        {
            curr->val += l2->val;
            
            if (l2->next || curr->val >= 10)
            {
                curr->next = new ListNode(curr->val/10);
                curr->val = curr->val % 10;
            }
            
            curr = curr->next;
            l2 = l2->next;
        }
        
        return head;
    }
};