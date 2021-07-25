// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

enum Direction { up, left, down, right, invalid };
struct Data {
    Data() : inDir(invalid) {}
    Data(Direction in, int X, int Y) : inDir(in), x(X), y(Y) {}
    Direction inDir;
    int x;
    int y;
};

class Solution {
private:
    static const Data data[6][invalid];

    bool validPath(const vector<vector<int>>& grid, Direction inDir, int x, int y) {
        int xEnd = grid.size() - 1;
        int yEnd = grid[0].size() - 1;

        int visited[xEnd+1][yEnd+1];
        memset(visited, 0, sizeof(visited));

        while (x <= xEnd && y <= yEnd && x >= 0 && y >= 0) {
            // Been here before
            if (visited[x][y] != 0) return false;
            visited[x][y] = 1;

            // Evaluate Direction To Go
            Data result = data[grid[x][y]-1][inDir];

            // Check for valid result
            if (result.inDir == invalid) return false;

            // If currently valid and at the end
            if (x == xEnd && y == yEnd) return true;

            x += result.x;
            y += result.y;
            inDir = result.inDir;
        }

        return false;
    }

public:
    bool hasValidPath(const vector<vector<int>>& grid) {
        if (grid.empty()) return false;
        if (grid.size() == 1 && grid[0].size() == 1) return true;

        switch (grid[0][0]) {
            case 1:
            case 6:
                return validPath(grid, Direction::left, 0, 1);
            case 2:
            case 3:
                return validPath(grid, up, 1, 0);
            case 4:
                // Special case: 2 potential streets
                return validPath(grid, up, 1, 0) || validPath(grid, Direction::left, 0, 1);
            case 5:
            default:
                // Special case: if size > 1, then it will never be true
                return false;
        }

        return false;
    }
};

const Data Solution::data[6][invalid] =  {
    {Data(), Data(Direction::left, 0, 1), Data(), Data(Direction::right, 0, -1)},
    {Data(Direction::up, 1, 0), Data(), Data(Direction::down, -1, 0), Data()},
    {Data(), Data(Direction::up, 1, 0), Data(), Data(Direction::right, 0, -1)},
    {Data(), Data(), Data(Direction::left, 0, 1), Data(Direction::up, 1, 0)},
    {Data(Direction::right, 0, -1), Data(Direction::down, -1, 0), Data(), Data()},
    {Data(Direction::left, 0, 1), Data(), Data(), Data(Direction::down, -1, 0)},
};