// https://leetcode.com/problems/valid-parentheses/

class Solution
{
    private:
        stack <char> bracket;
    public:
        bool isValid(string &s)
        {
            if (s.length() % 2 != 0)
                return false;

            for (auto c : s)
            {
                if (c == '(' || c == '{' || c == '[')
                    bracket.push(c);
                else if (bracket.empty())
                    return false;
                else if ((c == ')' && bracket.top() == '(') ||
                         (c == '}' && bracket.top() == '{') ||
                         (c == ']' && bracket.top() == '[')  )
                    bracket.pop();
                else return false;
            }

            return bracket.empty();
        }
};