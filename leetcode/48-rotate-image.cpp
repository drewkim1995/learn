// https://leetcode.com/problems/rotate-image/

class Solution
{
    public:
        void rotate(vector<vector<int>>& matrix)
        {
            int n = matrix.size() - 1;

            if (n < 1)
                return;

            for (int offset = 0; offset*2 < n; offset++)
            {
                int limit = n - offset;
                vector<int> top = matrix[offset];

                for (int i = offset; i < limit; i++)
                {
                    // Move left side to top
                    matrix[offset][n-i] = matrix[i][offset];

                    // Move bottom to left side
                    matrix[i][offset] = matrix[limit][i];

                    // Move right side to bottom
                    matrix[limit][i] = matrix[n-i][limit];

                    // Move copy of top to right side
                    matrix[n-i][limit] = top[n-i];

                    //print(matrix, i);
                }
            }
        }/*
        void print(vector<vector<int>>& matrix, int i)
        {
            int n = matrix.size()-1;
            cout << endl << "i = " << i << endl;
            for (int k = 0; k <= n; k++)
            {
                for (int j = 0; j <= n; j++)
                {
                    cout << matrix[k][j] << " ";
                }
                cout << endl;
            }
        }*/
};

/* Actual test cases:
[1,1,1,1,2],
[4,5,5,6,2],
[4,8,0,6,2],
[4,8,7,7,2],
[4,3,3,3,3]

[[1,1,1,1,2],[4,5,5,6,2],[4,8,0,6,2],[4,8,7,7,2],[4,3,3,3,3]]
[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
[[1,2,3],[4,5,6],[7,8,9]]
[[1,2],[3,4]]
*/