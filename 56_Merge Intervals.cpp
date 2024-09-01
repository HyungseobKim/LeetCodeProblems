class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int>& a, const std::vector<int>& b)
            {
                return a[1] < b[1];
            });
        
        for (int i = intervals.size() - 1; i > 0; --i)
        {
            std::vector<int>& curr = intervals[i];
            std::vector<int>& earlier = intervals[i-1];

            if (curr[0] <= earlier[1])
            {
                earlier[0] = std::min(earlier[0], curr[0]);
                earlier[1] = curr[1];
                intervals.erase(intervals.begin() + i);
            }
        }

        return intervals;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){ return a[0] < b[0]; });

        std::vector<std::vector<int>> result;
        std::vector<int>& standard = intervals[0];

        const int size = intervals.size();
        for (int i = 1; i < size; ++i)
        {
            const std::vector<int>& interval = intervals[i];

            if (interval[0] <= standard[1])
            {
                standard[1] = std::max(standard[1], interval[1]);
            }
            else
            {
                result.push_back(standard);
                standard = interval;
            }
        }

        result.push_back(standard);
        return result;
    }
};