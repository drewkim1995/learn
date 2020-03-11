// https://leetcode.com/problems/n-queens/

// Attempting Row by Row solution so we don't need to keep
// track of row number/count as we'll know because of vector.push_back()

// Note: Avoid using vector<bool> as it is not a STL container

class Solution
{
    private:
        vector<vector<string>> result;
        unsigned char * qCol;
        unsigned char * temp;

        void backtrack(const int n, const int qColSize)
        {
            // Vertical Check board is valid
            memcpy(temp, qCol, sizeof(unsigned char) * qColSize);
            sort(temp, temp+qColSize);
            for (int i = 1; i < qColSize; i++)
            {
                if (temp[i] == temp[i-1])
                    return;
            }

            // Diagonal Check board
            for (int row = 0; row < qColSize; row++)
            {
                // Top-left to bottom-right
                int col = qCol[row] + 1;
                for (int next = row+1; next < qColSize; next++, col++)
                    if (col == qCol[next])
                        return;

                // Top-right to bottom-left
                col = qCol[row] + 1;
                for (int next = row-1; next >= 0; next--, col++)
                    if (col == qCol[next])
                        return;
            }

            // Insert solution
            if (n == qColSize)
            {
                vector<string> solution (n, string(n, '.'));

                // Generate string here
                for (int i = 0; i < n; i++)
                    solution[i][qCol[i]] = 'Q';

                result.push_back(solution);
                return;
            }

            // Inserting a queen
            for (int col = 0; col < n; col++)
            {
                qCol[qColSize] = col;
                backtrack(n, qColSize+1);
                // Don't need to 'reset' since we keep track via qColSize
            }

            return;
        }

    public:
        vector<vector<string>> solveNQueens(const int n)
        {
            // Allocated on the stack implies that it will automatically be freed when the stack unwinds.
            qCol = (unsigned char *) alloca(sizeof(unsigned char) * n);
            temp = (unsigned char *) alloca(sizeof(unsigned char) * n);

            backtrack(n, 0);
            return result;
        }
};