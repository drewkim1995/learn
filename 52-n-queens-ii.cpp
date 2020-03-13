// https://leetcode.com/problems/n-queens/
// Note: Avoid using vector<bool> as it is not a STL container

class Solution
{
    private:
        int result;

        void solveNQueens(vector<string> & theory, const int n, const int row)
        {
            // Insert solution
            if (n == row)
            {
                ++result;
                return;
            }

            // Inserting a queen
            for (int col = 0; col < n; col++)
            {
                if (isValid(theory, n, row, col))
                {
                    theory[row][col] = 'Q';
                    solveNQueens(theory, n, row+1);
                    theory[row][col] = '.';
                }
            }
        }

        bool isValid(vector<string> & theory, const int n, const int row, const int col)
        {
            // Column Vertical Check board
            for (int i = 0; i < row; i++)
                if (theory[i][col] == 'Q')
                    return false;

            //  45° Diagonal (BL to TR) Check board
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
                if (theory[i][j] == 'Q')
                    return false;

            // 135° Diagonal (TL to BR) Check board
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
                if (theory[i][j] == 'Q')
                    return false;

            return true;
        }

    public:
        int totalNQueens(const int n)
        {
            vector<string> theory(n, string(n, '.'));
            solveNQueens(theory, n, 0);
            return result;
        }
};