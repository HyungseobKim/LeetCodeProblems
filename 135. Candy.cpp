class Solution {
public:
    int candy(vector<int>& ratings) {
        ratings.push_back(0);
        const int size = ratings.size();

        vector<long> table(size, -1);
        table.back() = 0;

        queue<pair<int, long>> tasks;
        tasks.push(make_pair(0, 0));

        stack<pair<int, long>> sub;

        while (!tasks.empty() || !sub.empty())
        {
            if (tasks.empty())
            {
                while (!sub.empty())
                {
                    tasks.push(sub.top());
                    sub.pop();
                }
            }

            const auto task = tasks.front();
            tasks.pop();

            const int index = task.first;
            const long value = task.second + 1;

            if (table[index] != -1)
                continue;

            const int curr = ratings[index];
            const int next = ratings[index + 1];

            if (curr < next)
            {
                table[index] = value;
                tasks.push(make_pair(index + 1, value));
            }
            else if (curr == next)
            {
                table[index] = value;
                tasks.push(make_pair(index + 1, 0));
            }
            else // curr > next
            {
                if (table[index + 1] == -1)
                {
                    tasks.push(make_pair(index + 1, 0));
                    sub.push(make_pair(index, value - 1));
                }
                else
                    table[index] = std::max(table[index + 1] + 1, value);
            }
        }

        return std::accumulate(table.begin(), table.end(), 0l);
    }
};