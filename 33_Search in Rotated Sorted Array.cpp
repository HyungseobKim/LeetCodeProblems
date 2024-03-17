class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        m_target = target;
        return search_rec(nums, 0, nums.size());
    }
    
private:
    int search_rec(const std::vector<int>& nums, int min, int max)
    {
        const int mid = (min + max) / 2;
        const int num = nums[mid];

        if (num == m_target)
        {
            return mid;
        }
        
        if (min+1 >= max)
        {
            return -1;
        }
        
        if (num < m_target)
        {
            // Try with right half.
            const int result = search_rec(nums, mid, max);

            // Success.
            if (result != -1)
            {
                return result;
            }

            // Greater numbers can be on the left half.
            if (num < nums[min])
            {
                return search_rec(nums, min, mid);
            }

            // Failed.
            return -1;
        }
        else // Target is smaller than middle number.
        {
            // Try with left half.
            const int result = search_rec(nums, min, mid);

            // Success.
            if (result != -1)
            {
                return result;
            }

            // Smaller numbers can be on the right half.
            if (num > nums[min])
            {
                return search_rec(nums, mid, max);
            }

            // Failed.
            return -1;
        }
    }
    
private:
    int m_target;
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;

        while (min <= max)
        {
            const int mid = (min + max) / 2;
            const int num_mid = nums[mid];

            if (num_mid == target)
            {
                return mid;
            }

            if (min == max)
            {
                return -1;
            }

            const int num_min = nums[min];
            const int num_max = nums[max];

            if (num_mid > num_max)
            {
                if (target < num_mid)
                {
                    if (target == num_min)
                    {
                        return min;
                    }

                    if (target < num_min)
                    {
                        if (min == mid)
                        {
                            ++min;
                        }
                        else
                        {
                            min = mid;
                        }
                    }
                    else
                    {
                        max = mid;
                    }
                }
                else
                {
                    if (min == mid)
                    {
                        ++min;
                    }
                    else
                    {
                        min = mid;
                    }
                }
            }
            else
            {
                if (target < num_mid)
                {
                    max = mid;
                }
                else
                {
                    if (target == num_max)
                    {
                        return max;
                    }

                    if (target < num_max)
                    {
                        if (min == mid)
                        {
                            ++min;
                        }
                        else
                        {
                            min = mid;
                        }
                    }
                    else
                    {
                        max = mid;
                    }
                }
            }
        }

        return -1;
    }
};