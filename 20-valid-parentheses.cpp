// https://leetcode.com/problems/valid-parentheses/

class Solution
{
    private:
        stack <char> bracket;
    public:
        bool isValid(string &s)
        {
            bool valid = true;

            if (s.length() % 2 != 0)
                valid = false;
            else
            {
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] == '(' ||
                        s[i] == '{' ||
                        s[i] == '[')
                        bracket.push(s[i]);
                    else if (!bracket.empty() &&
                            ((s[i] == ')' && bracket.top() == '(') ||
                             (s[i] == '}' && bracket.top() == '{') ||
                             (s[i] == ']' && bracket.top() == '['))  )
                    {
                        bracket.pop();
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }

            return (valid && bracket.empty());
        }
};