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
        const int size = lists.size();
        if (size == 0)
        {
            return nullptr;
        }

        auto compare = [&](int a, int b){ return lists[a]->val > lists[b]->val; };
        std::priority_queue<int, std::vector<int>, decltype(compare)> q(compare);

        for (int i = 0; i < size; ++i)
        {
            if (lists[i])
            {
                q.push(i);
            }
        }

        if (q.empty())
        {
            return nullptr;
        }

        const int headIndex = q.top();
        q.pop();

        ListNode* head = lists[headIndex];
        lists[headIndex] = head->next;
        
        if (lists[headIndex])
        {
            q.push(headIndex);
        }

        ListNode* next = head;

        while (q.size())
        {
            const int top = q.top();
            q.pop();

            next->next = lists[top];

            next = next->next;
            lists[top] = lists[top]->next;

            if (lists[top])
            {
                q.push(top);
            }
        }

        return head;
    }
};