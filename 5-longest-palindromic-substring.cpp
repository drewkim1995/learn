// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
    public:
        string longestPalindrome(string & s)
        {
            int start = 0;
            int maxLen = 0;

            if (s.empty())
                return "";

            for (int i = 0; i < s.length(); i++)
            {
                int lenOdd  = expandAroundCentre(s, i, i);      // e.g. aba
                int lenEven = expandAroundCentre(s, i, i+1);    // e.g. abba
                int len = max(lenOdd, lenEven);

                if (len > maxLen)
                {
                    start = i - (len-1) / 2;
                    maxLen = len;
                }
            }
            return s.substr(start,maxLen);
        }

        int expandAroundCentre(string & s, int left, int right)
        {
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }
            return right-left-1;
        }
};