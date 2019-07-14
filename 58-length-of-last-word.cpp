// https://leetcode.com/problems/length-of-last-word/

class Solution
{
    public:
        // Fix by sending reference not value
        int lengthOfLastWord(string s)
        {
            int len = 0;

            if (s.length() > 0)
            {
                size_t found = s.find_last_of(" ");
                if (found == s.length() - 1)
                    len = lengthOfLastWord(s.substr(0,s.length() - 1));
                else if (found != string::npos)
                    len = s.substr(found+1).length();
                else
                    len = s.length();
            }

            return len;
        }
};