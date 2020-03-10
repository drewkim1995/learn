// https://leetcode.com/problems/n-queens/

// Attempting Row by Row solution so we don't need to keep
// track of row number/count as we'll know because of vector.push_back()

class Solution
{
    private:
        vector<vector<string>> result;
        void backtrack(int n, vector<int> & qCol)
        {
            // Vertical Check board is valid
            vector<int> temp = qCol;
            sort(temp.begin(), temp.end()); // unique needs sorted vector
            auto it = unique(temp.begin(), temp.end());
            bool wasUnique = (it == temp.end());
            if (!wasUnique)
                return;

            // Diagonal Check board
            for (int row = 0; row < qCol.size(); row++)
            {
                // Top-left to bottom-right
                int col = qCol[row] + 1;
                for (int next = row+1; next < qCol.size(); next++, col++)
                    if (col == qCol[next])
                        return;

                // Top-right to bottom-left
                col = qCol[row] + 1;
                for (int next = row-1; next >= 0; next--, col++)
                    if (col == qCol[next])
                        return;
            }

            // Insert solution
            if (qCol.size() == n)
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
            for (int col = 0; col < n; col++)
            {
                qCol.push_back(col);
                backtrack(n, qCol);
                qCol.pop_back();
            }

            return;
        }

    public:
        vector<vector<string>> solveNQueens(int n)
        {
            vector<int> queensCol;
            backtrack(n, queensCol);
            return result;
        }
};