// https://leetcode.com/problems/n-queens/

// Attempting Row by Row solution so we don't need to keep
// track of row number/count as we'll know because of vector.push_back()

class Solution
{
    private:
        vector<vector<string>> result;
        void backtrack(int n, vector<int> & qCol, vector<vector<bool>> & board)
        {
            int size = qCol.size();

            // Insert solution
            if (size == n)
            {
                vector<string> solution;

                // Generate string here
                for (int i = 0; i < n; i++)
                {
                    string line(n, '.');
                    line[qCol[i]] = 'Q';
                    solution.push_back(line);
                }

                result.push_back(solution);
                return;
            }

            // Inserting a queen
            int row = size;
            int start = 0;
            for (int col = start; col < n; col++)
            {
                // Verify safe location to insert
                if (!board[row][col])
                    continue;

                // Updated board
                vector<vector<bool>> temp = board;
                updateBoard(temp, false, n, row, col);

                // Actual Inserting queen
                qCol.push_back(col);
                backtrack(n, qCol, temp);
                qCol.pop_back();

                //updateBoard(board, true, n, row, col);
            }

            return;
        }
        void updateBoard(vector<vector<bool>> & board, bool val, int n, int row, int col)
        {
            // Updated board
            for (int i = 0; i < n; i++)
            {
                // Vert and Horz
                board[row][i] = val;
                board[i][col] = val;

                // Diagonal Top-Left
                int r = row-i;
                int c = col-i;
                if(r >= 0 && c >= 0)
                    board[r][c] = val;

                // Diagonal Top-Right
                //r = row-i;
                c = col+i;
                if(r >= 0 && c <= n-1)
                    board[r][c] = val;

                // Diagonal Bottom-Left
                r = row+i;
                c = col-i;
                if(r <= n-1 && c >= 0)
                    board[r][c] = val;

                // Diagonal Bottom-Right
                r = row+i;
                c = col+i;
                if(r <= n-1 && c <= n-1)
                    board[r][c] = val;
            }
        }

    public:
        vector<vector<string>> solveNQueens(int n)
        {
            vector<bool> row(n, true);
            vector<vector<bool>> board (n, row);

            vector<int> queensCol;
            backtrack(n, queensCol, board);
            return result;
        }
};