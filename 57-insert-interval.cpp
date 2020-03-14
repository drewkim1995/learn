// https://leetcode.com/problems/insert-interval/

class Solution
{
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
        {
            vector<vector<int>> result;
            bool inserted = false;
            int size = intervals.size();
            if (size == 0)
                return {newInterval};

            vector<int> temp = intervals[0];

            for (int i = 0; i < size; ++i)
            {
                // Normal Merge Interval
                if (temp[1] < intervals[i][0])
                {
                    result.push_back(temp);
                    temp = intervals[i];
                }
                else
                {
                    temp[0] = min(temp[0], intervals[i][0]);
                    temp[1] = max(temp[1], intervals[i][1]);
                }

                // For inserting the new interval
                if (!inserted && temp[1] >= newInterval[0])
                {
                    if (temp[0] > newInterval[0] && temp[0] > newInterval[1])
                        result.push_back(newInterval);
                    else
                    {
                        temp[0] = min(temp[0], newInterval[0]);
                        temp[1] = max(temp[1], newInterval[1]);
                    }
                    inserted = true;
                }
            }
            result.push_back(temp);

            if (!inserted)
                result.push_back(newInterval);

            return result;
        }
};