/*
	The best solution by a guy from leetcode solutions.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums)
        {
            if (sub.empty() || sub[sub.size() - 1] < x)
            {
                sub.push_back(x);
            } else
            {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the first element >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};

/*
	My solution
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size = nums.size();

        table = std::vector<int>(size, -1);
        table.back() = 1;

        sortedIndices = std::vector<int>(size);
        std::iota(sortedIndices.begin(), sortedIndices.end(), 0);
        std::sort(sortedIndices.begin(), sortedIndices.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        nextGreater = std::vector<int>(size);
        for (int i = 0; i < size; ++i)
        {
            nextGreater[sortedIndices[i]] = i + 1;
        }

        for (int i = size - 1; i > 0; --i)
        {
            const int curr = sortedIndices[i];
            const int prev = sortedIndices[i-1];

            if (nums[curr] == nums[prev])
            {
                nextGreater[prev] = nextGreater[curr];
            }
        }

        int best = 0;

        for (int i = 0; i < size; ++i)
        {
            best = std::max(best, lengthOfLIS_rec(nums, i));
        }

        return best;
    }

private:
    int lengthOfLIS_rec(const std::vector<int>& nums, int index)
    {
        if (table[index] > -1)
        {
            return table[index];
        }
		
        int best = 1;

        for (int i = nextGreater[index]; i < size; ++i)
        {
            if (index < sortedIndices[i])
            {
                best = std::max(best, lengthOfLIS_rec(nums, sortedIndices[i]) + 1);
            }
        }

        table[index] = best;
        return best;
    }

    std::vector<int> nextGreater;
    std::vector<int> sortedIndices;
    std::vector<int> table;
    int size;
};

/*
	The same solution to the previous one but hashed before recursion.
	However, it's slower somehow. I don't know why.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size = nums.size();

        table = std::vector<int>(size, -1);
        table.back() = 1;

        sortedIndices = std::vector<int>(size);
        std::iota(sortedIndices.begin(), sortedIndices.end(), 0);
        std::sort(sortedIndices.begin(), sortedIndices.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        nextGreater = std::vector<int>(size);
        for (int i = 0; i < size; ++i)
        {
            nextGreater[sortedIndices[i]] = i + 1;
        }

        for (int i = size - 1; i > 0; --i)
        {
            const int curr = sortedIndices[i];
            const int prev = sortedIndices[i-1];

            if (nums[curr] == nums[prev])
            {
                nextGreater[prev] = nextGreater[curr];
            }
        }

        greaterIndices = std::vector<std::vector<int>>(size, std::vector<int>());
        for (int i = 0; i < size; ++i)
        {
            for (int j = nextGreater[i]; j < size; ++j)
            {
                if (i < sortedIndices[j])
                {
                    greaterIndices[i].push_back(sortedIndices[j]);
                }
            }
        }

        int best = 0;

        for (int i = 0; i < size; ++i)
        {
            best = std::max(best, lengthOfLIS_rec(nums, i));
        }

        return best;
    }

private:
    int lengthOfLIS_rec(const std::vector<int>& nums, int index)
    {
        if (table[index] > -1)
        {
            return table[index];
        }
        
        int best = 1;

        for (int i : greaterIndices[index])
        {
            best = std::max(best, lengthOfLIS_rec(nums, i) + 1);
        }

        table[index] = best;
        return best;
    }

    std::vector<std::vector<int>> greaterIndices;
    std::vector<int> nextGreater;
    std::vector<int> sortedIndices;
    std::vector<int> table;
    int size;
};