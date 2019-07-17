// https://leetcode.com/problems/pascals-triangle-ii/

class Solution
{
    public:
        vector<int> getRow(int k)
        {
            vector<int> row (1,1);

            for (int rowIndex = 1; rowIndex <= k; rowIndex++)
            {
                // Work in reverse order
                for (int colIndex = rowIndex-1; colIndex > 0; colIndex--)
                    row[colIndex] = row[colIndex - 1] + row[colIndex];

                row.push_back(1);
            }

            return row;
        }
};