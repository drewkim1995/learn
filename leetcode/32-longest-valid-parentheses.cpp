// https://leetcode.com/problems/longest-valid-parentheses/

class Solution
{
    public:
        int longestValidParentheses(string &s)
        {
            // Counts
            int open = 0;
            int close = 0;
            int longest = 0;

            for (int i = 0; i < s.length(); i++)
            {
                // Tracking Open/Closed
                if (s[i] == '(')
                    open++;
                else
                    close++;

                // Valid Parentheses
                if (open == close)
                {
                    int currentLength = close*2;
                    if (currentLength > longest)
                        longest = currentLength;
                }
                else if (close > open)
                {
                    open = 0;
                    close = 0;
                }
            }


            // Again in reverse
            open = 0;
            close = 0;

            for (int i = s.length()-1; i >= 0; i--)
            {
                // Tracking Open/Closed
                if (s[i] == '(')
                    open++;
                else
                    close++;

                // Valid Parentheses
                if (open == close)
                {
                    int currentLength = close*2;
                    if (currentLength > longest)
                        longest = currentLength;
                }
                else if (open > close)
                {
                    open = 0;
                    close = 0;
                }
            }

            return longest;
        }
};