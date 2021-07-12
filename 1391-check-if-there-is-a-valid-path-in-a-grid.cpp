// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

class Solution {
private:
    vector<vector<int>> grid;
    const enum Direction { up, left, down, right, size };

public:
    bool hasValidPath(vector<vector<int>>& in) {
        if (in.empty()) return false;
        if (in.size() == 1 && in[0].size() == 1) return true;

        grid = in;

        switch (grid[0][0]) {
            case 1:
            case 6:
                return validPath(left, 0, 1);
            case 2:
            case 3:
                return validPath(up, 1, 0);
            case 4:
                // Special case: 2 potential streets
                return validPath(up, 1, 0) || validPath(left, 0, 1);
            case 5:
            default:
                // Special case: if size > 1, then it will never be true
                return false;
        }

        return false;
    }

private:
    bool validPath(Direction inDir, int x, int y) {
        int xEnd = grid.size() - 1;
        int yEnd = grid[0].size() - 1;

        int visited[xEnd+1][yEnd+1];
        memset(visited, 0, sizeof(visited));

        while (x <= xEnd && y <= yEnd && x >= 0 && y >= 0) {
            // Been here before
            if (visited[x][y] != 0) return false;
            visited[x][y] = 1;

            Direction out;
            // Evaluate Direction To Go
            switch (grid[x][y]) {
                case 1:
                    if (inDir == left) {
                        if (x == xEnd && y == yEnd) return true;
                        ++y;
                        out = right;
                    }
                    else if (inDir == right) {
                        if (x == xEnd && y == yEnd) return true;
                        --y;
                        out = left;
                    }
                    else return false;
                    break;
                case 2:
                    if (inDir == up) {
                        if (x == xEnd && y == yEnd) return true;
                        ++x;
                        out = down;
                    }
                    else if (inDir == down) {
                        if (x == xEnd && y == yEnd) return true;
                        --x;
                        out = up;
                    }
                    else return false;
                    break;
                case 3:
                    if (inDir == left) {
                        if (x == xEnd && y == yEnd) return true;
                        ++x;
                        out = down;
                    }
                    else if (inDir == down) {
                        if (x == xEnd && y == yEnd) return true;
                        --y;
                        out = left;
                    }
                    else return false;
                    break;
                case 4:
                    if (inDir == right) {
                        if (x == xEnd && y == yEnd) return true;
                        ++x;
                        out = down;
                    }
                    else if (inDir == down) {
                        if (x == xEnd && y == yEnd) return true;
                        ++y;
                        out = right;
                    }
                    else return false;
                    break;
                case 5:
                    if (inDir == left) {
                        if (x == xEnd && y == yEnd) return true;
                        --x;
                        out = up;
                    }
                    else if (inDir == up) {
                        if (x == xEnd && y == yEnd) return true;
                        --y;
                        out = left;
                    }
                    else return false;
                    break;
                case 6:
                    if (inDir == right) {
                        if (x == xEnd && y == yEnd) return true;
                        --x;
                        out = up;
                    }
                    else if (inDir == up) {
                        if (x == xEnd && y == yEnd) return true;
                        ++y;
                        out = right;
                    }
                    else return false;
                    break;
                default:
                    return false;
            }

            // Flip it for next cycle
            inDir = (Direction)((out + 2) % size);
        }

        return false;
    }
};