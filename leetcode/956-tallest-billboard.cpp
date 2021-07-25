// https://leetcode.com/problems/tallest-billboard/

// Cannot remove dupes as it would fail a test case like this:
// [1,2,3,3,3,2,1]

class Solution {
private:
    int retVal = 0;
    int size = 0;

public:
    int tallestBillboard(vector<int>& rods) {
        // Could convert into arr instead of vector
        size = rods.size();
        if (size > 1) {
            int left_count = 0, right_count = 0;
            sort(rods.begin(), rods.end(), greater<int>());
            for (auto num : rods) left_count += num;

            search(rods, 0, left_count, right_count);
        }

        return retVal;
    }

private:
    void search(vector<int>& l, int lIter, int lCount, int rCount) {
        // Invalid
        if (lCount < rCount) return;

        // Match
        if (lCount == rCount && lCount > retVal) {
            for (int i = 0; i < size; i++) cout << l[i] << " ";
            cout << endl << "left iter = " << lIter << endl;
            cout << "count = " << lCount << endl << endl;
            retVal = lCount;
            return;
        }

        // Error
        if (lIter == size) return;

        for (int i = lIter; i < size; ++i) {
            // Option 1: Move number to RHS
            search(l, i + 1, lCount - l[i], rCount + l[i]);

            // Option 2: Remove the number
            search(l, i + 1, lCount - l[i], rCount);
        }

    }
};
/*
[1,2,3,6]
[1,2,3,4,5,6]
[1,2]
[5]
[100,100]
[1,5,100,100,5,1]
[1,5,100,100,100,100,5,1]
[1,2,3,3,3,2,1]
[1,3,6,5,3,1,3,74,133,999,1,74,345,123,346,536,313,345,7,235]
[1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123]
*/