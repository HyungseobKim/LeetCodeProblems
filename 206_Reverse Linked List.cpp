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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
        {
            return nullptr;
        }

        return reverseList_iter(head);
    }

private:
    ListNode* reverseList_iter(ListNode* head)
    {
        ListNode* prev = nullptr;

        while (head)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    ListNode* reverseList_rec(ListNode* head)
    {
        ListNode* prev = nullptr;
        head = reverseList_rec_aux(head, prev);
        prev->next = nullptr;
        return head;
    }

    ListNode* reverseList_rec_aux(ListNode*& node, ListNode*& prev)
    {
        if (node->next == nullptr)
        {
            prev = node;
            return node;
        }

        ListNode* head = reverseList_rec_aux(node->next, prev);
        prev->next = node;
        prev = node;

        return head;
    }
};