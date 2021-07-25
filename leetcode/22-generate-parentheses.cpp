// https://leetcode.com/problems/generate-parentheses/

class Solution
{
    private:
        int n;
        void gen(vector<string> & v, string path, int open, int close, int current)
        {
            if (open  > n/2 ||
                close > n/2 ||
                close > open)
                return;
            if (current == n && open == close)
            {
                v.push_back(path);
                return;
            }

            // Improvements
            if (open == close)
                gen(v, path + "(", open+1, close, current+1);
            else if (open == n/2)
                gen(v, path + ")", open, close+1, current+1);
            else
            {
                gen(v, path + "(", open+1, close, current+1);
                gen(v, path + ")", open, close+1, current+1);
            }
        }

    public:
        vector<string> generateParenthesis(int target)
        {
            if (target < 1)
                return {""};
            else
                n = target * 2;

            vector<string> ret;

            gen(ret, "(", 1, 0, 1);

            return ret;
        }
};