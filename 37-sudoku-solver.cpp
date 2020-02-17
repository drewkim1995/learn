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

            for (int i = 0; i < 9; i++)
            {
                rowCand[i] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                colCand[i] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
                boxCand[i] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            }

            // Getting Candidates
            for (int col = 0; col < 9; col++)
            {
                for (int row = 0; row < 9; row++)
                {
                    char colVal = board[row][col];
                    int boxIndex = getBoxIndex(row, col);
                    if (colVal != '.')
                    {
                        colCand[col].erase(colVal);
                        boxCand[boxIndex].erase(colVal);
                    }
                    else
                        spaces.insert(make_pair(row, col));

                    // Getting Rows
                    char rowVal = board[col][row];
                    if (rowVal != '.')
                        rowCand[col].erase(rowVal);

                }
            }

            /* Print Cell [2,0]
            set<char> temp1, temp2, result;
            set_intersection(rowCand[0].begin(), rowCand[0].end(), colCand[3].begin(), colCand[3].end(), inserter(temp1, temp1.begin()));
            set_intersection(colCand[3].begin(), colCand[3].end(), boxCand[1].begin(), boxCand[1].end(), inserter(temp2, temp2.begin()));
            set_intersection(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(result, result.begin()));
            cout << "Cell[2,0] = {";
            cout << endl;
            for (auto n : rowCand[0])
                cout << n << ", ";
            cout << endl;
            for (auto n : colCand[3])
                cout << n << "| ";
            cout << endl;
            for (auto n : boxCand[1])
                cout << n << "+ ";
            cout << endl;
            for (auto n : result)
                cout << n << "& ";
            cout << endl;
            cout << "}" << endl;*/

            while(!spaces.empty())
            {
                for(auto indicies : spaces)
                {
                    int row = indicies.first;
                    int col = indicies.second;
                    char val = board[row][col];
                    if (val == '.')
                    {
                        int box = getBoxIndex(row, col);

                        set<char> temp1, temp2, result;
                        set_intersection(rowCand[row].begin(), rowCand[row].end(), colCand[col].begin(), colCand[col].end(), inserter(temp1, temp1.begin()));
                        set_intersection(colCand[col].begin(), colCand[col].end(), boxCand[box].begin(), boxCand[box].end(), inserter(temp2, temp2.begin()));
                        set_intersection(temp1.begin(), temp1.end(), temp2.begin(), temp2.end(), inserter(result, result.begin()));
                        //cout << "Cell[2,0] = {";
                        //for (auto n : result)
                        //    cout << n << ", ";

                        //cout << "Options: " << result.size() << " | " << row << "," << col << endl;
                        //cout << boxCand[box].size() << endl;

                        // Inserting to original board
                        if (result.size() == 1)
                        {
                            int ins = *result.begin();
                            board[row][col] = ins;
                            boxCand[box].erase(ins);
                            rowCand[row].erase(ins);
                            colCand[col].erase(ins);
                            spaces.erase(indicies);
                        }
                    }
                }
            }

            return;
        }
};