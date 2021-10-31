https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string sub, string original) {
        int iter = 0;

        for (int i = 0; i < original.length(); i++) {
            if (sub[iter] == original[i]) {
                iter++;
            }

            if (iter == sub.length())
                return true;
        }

        return sub == original;
    }
};