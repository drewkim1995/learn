// https://leetcode.com/problems/valid-sudoku/
/* Test case:
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
[["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
*/

class Solution
{
    private:
        bool isValidSub(vector<vector<char>>& board, const int x, const int y)  // Coordinate(x,y) is top left corner
        {
            map<char, char> check;

            // Get Vertical
            for (int row = x; row < x + 3; row++)
            {
                for (int col = y; col < y + 3; col++)
                {
                    if (board[row][col] != '.')
                    {
                        if (!check.insert(make_pair(board[row][col], '1')).second)
                            return false;
                    }
                }
            }

            return true;
        }

    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            // Check Vertical Line
            for (int row = 0; row < 9; row++)
            {
                map<char, char> check;

                for (int col = 0; col < 9; col++)
                {
                    if (board[row][col] != '.')
                    {
                        if (!check.insert(make_pair(board[row][col], '1')).second)
                            return false;
                    }
                }
            }

            // Check Horizontal Line
            for (int col = 0; col < 9; col++)
            {
                map<char, char> check;

                for (int row = 0; row < 9; row++)
                {
                    if (board[row][col] != '.')
                    {
                        if (!check.insert(make_pair(board[row][col], '1')).second)
                            return false;
                    }
                }
            }

            // Check Sub Boxes
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    if (!isValidSub(board, x * 3, y * 3))
                        return false;
                }
            }

            return true;
        }
};