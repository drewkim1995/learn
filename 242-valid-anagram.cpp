// https://leetcode.com/problems/valid-anagram/

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            // Check length first?
            if (s.length() != t.length())
                return false;

            // Sort strings
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());

            for(int i = 0; i < s.length(); i++)
                if (s[i] != t[i])
                    return false;

            return true;
        }
};