/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int result = -1;
        
        bool remain = true;
        int rangeMin = 0;
        int rangeMax = mountainArr.length();
        
        int min = 0;
        int max = 0;
        int mid = 0;
        
        while(remain)
        {
            remain = false;
            
            min = rangeMin;
            max = rangeMax;
            mid = (min+max)/2;
            
            while(mid < max && min < mid)
            {
                int curr = mountainArr.get(mid);

                if (curr == target)
                {
                    if (mountainArr.get(mid-1) > curr)
                    {
                        result = mid;
                        max = mid-1;
                    }
                    else
                        return mid;
                }
                else if (target < curr)
                {
                    max = mid;
                    if (rangeMin < mid)
                    {
                        rangeMin = mid;
                        remain = true;
                    }
                }
                else // curr < target
                {
                    if (mountainArr.get(mid-1) > curr)
                    {
                        max = mid;
                        rangeMax = mid;
                    }
                    else
                    {
                        if (curr > mountainArr.get(mid+1))
                            return -1;
                        
                        min = mid;
                        rangeMin = mid;
                    }
                }

                mid = (min+max)/2;
            }
            
            if (mountainArr.get(mid) == target)
                return mid;
            
        }
        
        return result;
    }
};