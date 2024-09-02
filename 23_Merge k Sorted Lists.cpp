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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto Compare = [](ListNode* node1, ListNode* node2){ return node1->val > node2->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(Compare)> q(Compare);

        // Push all valid head nodes to the priority queue.
        for (ListNode* head : lists)
        {
            if (head)
            {
                q.push(head);
            }
        }

        // If the q is empty, there was no valid node.
        if (q.empty())
        {
            return nullptr;
        }

        // Store the head node to return.
        ListNode* head = q.top();
        q.pop();
        if (head->next)
        {
            q.push(head->next);
        }

        // Get the tail node to attach the sorted nodes.
        ListNode* tail = head;

        while (q.size())
        {
            // Get the smallest node.
            ListNode* node = q.top();
            q.pop();

            // Attach to the tail node and make it be the new tail.
            tail->next = node;
            tail = node;

            // Push the linked node to the priority queue.
            if (node->next)
            {
                q.push(node->next);
            }
        }

        return head;
    }
};