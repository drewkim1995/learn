// https://leetcode.com/problems/insert-interval/

class Solution
{
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
        {
            vector<vector<int>> result;
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end());
            int size = intervals.size();

            if (size == 0)
                return result;

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