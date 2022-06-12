class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto cmp = [](std::pair<int, int> left, std::pair<int, int> right){
            if (left.first == right.first)
            {
                return left.second < right.second;
            }
            
            return left.first < right.first;
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> queue(cmp);
        
        const int size = static_cast<int>(nums.size());
        std::vector<int> answer(size - k + 1);
     
        // Push elements of the first window except the last element.
        for (int i = 0; i < k - 1; ++i)
        {
            queue.push(std::make_pair(nums[i], i));
        }
        
        for (int left = 0, right = k - 1; right < size; ++left, ++right)
        {
            // Push the new element.
            queue.push(std::make_pair(nums[right], right));
            
            std::pair<int, int> max = queue.top();
            
            // Find the greatest element in the current window.
            while (max.second < left)
            {
                queue.pop();
                max = queue.top();
            }
            
            answer[left] = max.first;
        }
        
        return answer;
    }
};