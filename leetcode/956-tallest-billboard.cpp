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
        int dupes = 0;
        vector<int> sortedRods;
        if (size > 1) {
            sort(rods.begin(), rods.end(), greater<int>());
            int left_count = 0, right_count = 0;
            for (int i = 0; i < size-1; ++i) {
                int num = rods[i];
                int numNext = rods[i+1];
                if (num != numNext) {
                    left_count += num;
                    sortedRods.push_back(num);

                    // Add the last num
                    if (i == size-2) {
                        left_count += numNext;
                        sortedRods.push_back(numNext);
                    }
                }
                else {
                    dupes += num;
                    ++i;
                }
            }

            size = sortedRods.size();
            search(sortedRods, 0, left_count, right_count);

            if (retVal != 0 || size == 0) retVal += dupes;
        }
        return retVal;
    }

private:
    void search(vector<int>& l, int lIter, int lCount, int rCount) {
        // Invalid
        if (lCount < rCount) return;

        // Match
        if (lCount == rCount && lCount > retVal) {
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