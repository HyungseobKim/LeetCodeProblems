class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Step 1: find where to place newStart
        int min = 0;
        int max = intervals.size();

        const int newStart = newInterval[0];
        
        while (min < max)
        {
            const int mid = (min + max) / 2;
            const int start = intervals[mid][0];

            if (start == newStart)
            {
                min = mid;
                max = mid;
            }
            else if (newStart < start)
            {
                max = mid;
            }
            else
            {
                if (min == mid)
                {
                    --max;
                }
                else
                {
                    min = mid;
                }
            }
        }

        // intervals[startIndex][0] <= newStart
        const int startIndex = (min + max) / 2;

        // Step 2: find where to place newEnd
        min = 0;
        max = intervals.size();

        const int newEnd = newInterval[1];

        while (min < max)
        {
            const int mid = (min + max) / 2;
            const int end = intervals[mid][1];

            if (end == newEnd)
            {
                min = mid;
                max = mid;
            }
            else if (newEnd < end)
            {
                max = mid;
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

        // intervals[endIndex][1] >= newEnd
        const int endIndex = (min + max) / 2;

        // Step 3: insert newInterval
        
        // Special case 1: intervals is empty + a
        if (startIndex >= intervals.size())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        // Special case 2: newStart is the smallest start (implies startIndex is 0)
        if (newStart < intervals[startIndex][0])
        {
            // newInterval overlaps with the entire intervals
            if (endIndex >= intervals.size())
            {
                return std::vector<std::vector<int>>(1, newInterval);
            }

            if (newEnd < intervals[endIndex][0])
            {
                if (endIndex == 0)
                {
                    intervals.insert(intervals.begin(), newInterval);
                }
                else
                {
                    intervals[0] = newInterval;
                    EraseIntervals(intervals, 1, endIndex);
                }
            }
            else // newEnd overlaps with intervals[endIndex]
            {
                intervals[0][0] = newStart;
                intervals[0][1] = intervals[endIndex][1];
                EraseIntervals(intervals, 1, endIndex + 1);
            }

            return intervals;
        }

        // Special case 3: newEnd is outside the bound
        if (endIndex >= intervals.size())
        {
            if (newStart <= intervals[startIndex][1])
            {
                intervals[startIndex][1] = newEnd;
                EraseIntervals(intervals, startIndex + 1, endIndex); // note endIndex is already greater than the last index, so we don't need to +1.
            }
            else // newStart is not inside of a particular interval
            {
                // There IS NO existing interval behind startIndex
                if (startIndex + 1 == intervals.size())
                {
                    intervals.push_back(newInterval);
                }
                else // There IS existing interval behind startIndex
                {
                    intervals[startIndex+1] = newInterval;
                    EraseIntervals(intervals, startIndex + 2, endIndex);  // note endIndex is already greater than the last index, so we don't need to +1.
                }
            }

            return intervals;
        }

        // Normal cases: one or both of newStart and newEnd is/are inside of an existing interval
        if (newStart <= intervals[startIndex][1])
        {
            if (newEnd < intervals[endIndex][0])
            {
                intervals[startIndex][1] = newEnd;
                EraseIntervals(intervals, startIndex + 1, endIndex);
            }
            else // newEnd overlaps with intervals[endIndex]
            {
                intervals[startIndex][1] = intervals[endIndex][1];
                EraseIntervals(intervals, startIndex + 1, endIndex + 1);
            }

            return intervals;
        }

        if (newEnd >= intervals[endIndex][0])
        {
            intervals[endIndex][0] = newStart;
            EraseIntervals(intervals, startIndex + 1, endIndex);
            
            return intervals;
        }

        // Special case 4: newStart and newEnd aren't inside any interval but they totally consumes some intervals
        if (startIndex + 1 < endIndex)
        {
            intervals[startIndex+1] = newInterval;
            EraseIntervals(intervals, startIndex + 2, endIndex);
            return intervals;
        }

        // Last case: newInterval doesn't overlap with any other intervals
        intervals.insert(intervals.begin() + endIndex, newInterval);
        return intervals;
    }

private:
    void EraseIntervals(std::vector<std::vector<int>>& intervals, int eraseStart, int eraseEnd)
    {
        if (eraseStart <= eraseEnd)
        {
            intervals.erase(intervals.begin() + eraseStart, intervals.begin() + eraseEnd);
        }
    }
};