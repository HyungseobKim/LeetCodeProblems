class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> table;

        for (const int num : nums)
        {
            if (table.find(num) == table.end())
            {
                table[num] = 1;
            }
            else
            {
                table[num] = table[num] + 1;
            }
        }

        auto compare = [&](int num1, int num2){ return table[num1] < table[num2]; };
        std::priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);

        for (const auto& itr : table)
        {
            pq.push(itr.first);
        }

        std::vector<int> answer(k);
        for (int i = 0; i < k; ++i)
        {
            answer[i] = pq.top();
            pq.pop();
        }

        return answer;
    }
};