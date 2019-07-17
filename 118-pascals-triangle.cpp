// https://leetcode.com/problems/pascals-triangle/

class Solution
{
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>> ret;

            for (int row = 1; row <= numRows; row++)
            {
                // Fill Constructor
                vector<int> v(row, 1);

                for (int col = 1; col < row-1; col++)
                    v[col] = ret[row-2][col-1] + ret[row-2][col];

                ret.push_back(v);
            }

            return ret;
        }
};