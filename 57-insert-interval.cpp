// https://leetcode.com/problems/insert-interval/

class Solution
{
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
        {
            vector<vector<int>> result;
            int size = intervals.size();

            // No longer doing a sort then insert
            for (int i = 0; i < size; ++i)
            {
                if (intervals[i][0] == newInterval[0])
                {
                    if (intervals[i][1] < newInterval[1])
                        intervals.insert(intervals.begin() + i+1, newInterval);
                    else
                        intervals.insert(intervals.begin() + i, newInterval);
                    break;
                }
                else if (intervals[i][0] > newInterval[0])
                {
                    intervals.insert(intervals.begin() + i, newInterval);
                    break;
                }
            }

            if (intervals.size() == size++)
                intervals.push_back(newInterval);

            vector<int> temp = intervals[0];

            for (int i = 1; i < size; ++i)
            {
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
            }
            result.push_back(temp);

            return result;
        }
};