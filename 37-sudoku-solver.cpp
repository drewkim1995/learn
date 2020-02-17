// https://leetcode.com/problems/sudoku-solver/

class Solution
{
    private:
        int getBoxIndex(int row, int col)
        {
            int index = 0;
            if (row < 3)
            {
                // Boxes are either 0, 3, 6
                if (col < 3)
                    index = 0;
                else if (col < 6)
                    index = 3;
                else
                    index = 6;
            }
            else if (row < 6)
            {
                // Boxes are either 1, 4, 7
                if (col < 3)
                    index = 1;
                else if (col < 6)
                    index = 4;
                else
                    index = 7;
            }
            else
            {
                // Boxes are either 2, 5, 8
                if (col < 3)
                    index = 2;
                else if (col < 6)
                    index = 5;
                else
                    index = 8;
            }
            return index;
        }

    public:
        void solveSudoku(vector<vector<char>>& board)
        {
            // Init
            int box = 0;
            set<pair<int, int>> spaces;
            set<char> rowCand[9];
            set<char> colCand[9];
            set<char> boxCand[9];

            // Getting Candidates
            for (int col = 0; col < 9; col++)
            {
                for (int row = 0; row < 9; row++)
                {
                    char colVal = board[row][col];
                    int boxIndex = getBoxIndex(row, col);
                    if (colVal != '.')
                    {
                        colCand[col].insert(colVal);
                        boxCand[boxIndex].insert(colVal);
                    }
                    else
                        spaces.insert(make_pair(row, col));

                    // Getting Rows
                    char rowVal = board[col][row];
                    if (rowVal != '.')
                        rowCand[col].insert(rowVal);

                }
            }

            // Print Cell [0,2]
            auto result = rowCand[0];
            result.insert(colCand[2].begin(), colCand[2].end());
            result.insert(boxCand[0].begin(), boxCand[0].end());
            cout << "Cell[0,2] = {";
            for (auto n : result)
                cout << n << ", ";
            cout << "}" << endl;

            while(!spaces.empty())
            {
                for(auto indicies : spaces)
                {
                    int row = indicies.first;
                    int col = indicies.second;
                    char val = board[row][col];
                    if (val == '.')
                    {
                        set<char> options = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                        int box = getBoxIndex(row, col);

                        auto combo = rowCand[row];
                        combo.insert(colCand[col].begin(), colCand[col].end());
                        combo.insert(boxCand[box].begin(), boxCand[box].end());

                        for (auto num : combo)
                            options.erase(num);

                        // Inserting to original board
                        if (options.size() == 1)
                        {
                            int ins = *options.begin();
                            board[row][col] = ins;
                            boxCand[box].insert(ins);
                            rowCand[row].insert(ins);
                            colCand[col].insert(ins);
                            spaces.erase(indicies);
                        }
                    }
                }
            }

            return;
        }
};