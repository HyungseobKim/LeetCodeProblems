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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool moveSlow = false;

        while (fast)
        {
            if (moveSlow)
            {
                slow = slow->next;
            }
            moveSlow = !moveSlow;

            fast = fast->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};