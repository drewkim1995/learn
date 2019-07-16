// https://leetcode.com/problems/generate-parentheses/

class Solution
{
    private:
        void gen(vector<string> & v, string path, int open, int close, int current, const int n)
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

            gen(v, path + "(", open+1, close, current+1, n);
            gen(v, path + ")", open, close+1, current+1, n);
        }

    public:
        vector<string> generateParenthesis(int n)
        {
            if (n < 1)
                return {""};

            vector<string> ret;

            gen(ret, "(", 1, 0, 1, n*2);

            return ret;
        }
};