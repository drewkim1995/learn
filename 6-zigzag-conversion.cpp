// https://leetcode.com/problems/zigzag-conversion/

class Solution
{
    public:
        string convert(string & s, int numRows)
        {
            int numCols = s.length();

            if (numCols == 0)
                return "";

            char arr [numRows][numCols] = {};

            bool dirDown = true;
            int row = 0;
            int col = 0;

            for (auto c : s)
            {
                // Assign
                arr[row][col] = c;

                // Change Directions
                if (row == numRows-1)
                    dirDown = false;
                else if (row == 0)
                    dirDown = true;

                // Move rows
                if (numRows == 1)
                    col++;
                else if (dirDown)
                    row++;
                else
                {
                    row--;
                    col++;
                }
            }

            string ret;

            for (int i = 0; i < numRows; i++)
            {
                for (int j = 0; j < numCols; j++)
                {
                    if (arr[i][j] != NULL)
                        ret += arr[i][j];
                    if (ret.size() == numCols)
                        return ret;
                }
            }

            return ret;
        }
};