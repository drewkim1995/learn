// https://leetcode.com/problems/pascals-triangle/

class Solution
{
    public:
        vector<vector<int>> generate(int numRows)
        {
            vector<vector<int>> ret = {{1},{1,1}};

            if (numRows < 1)
                return {};
            else if (numRows == 1)
                return {{1}};

            for (int row = 2; row < numRows; row++)
            {
                vector<int> v;

                for (int col = 0; col < row+1; col++)
                {
                    if (col == 0 || col == row)
                        v.push_back(1);
                    else
                        v.push_back(ret[row-1][col-1] + ret[row-1][col]);
                }

                ret.push_back(v);
            }

            return ret;
        }
};