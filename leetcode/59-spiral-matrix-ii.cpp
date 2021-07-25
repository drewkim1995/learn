// https://leetcode.com/problems/spiral-matrix-ii/

class Solution
{
    public:
        vector<vector<int>> generateMatrix(int n)
        {
            if (n < 1)
                return {};

            vector<vector<int>> result(n, vector<int>(n));
            int num = 0;

            int rowLoop = 0;
            int colLoop = 1;

            int row = -1; // Ensure that it initially starts at 0
            int col = -1; // Ensure that it initially starts at 0

            while(num < n*n)
            {
                // Left to Right
                int limit = rowLoop++/2;
                for (++row, ++col; col < n - limit; ++col)
                    result[row][col] = ++num;

                // Top to Bottom
                limit = colLoop++/2;
                for (++row, --col; row < n - limit; ++row)
                    result[row][col] = ++num;

                // Half way exit
                if (num >= n*n)
                    break;

                // Right to Left
                limit = rowLoop++/2;
                for (--row, --col; col >= 0 + limit; --col)
                    result[row][col] = ++num;

                // Bottom to Top
                limit = colLoop++/2;
                for (--row, ++col; row >= 0 + limit; --row)
                    result[row][col] = ++num;
            }

            return result;
        }
};