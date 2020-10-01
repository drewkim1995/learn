// https://leetcode.com/problems/valid-anagram/

class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            // Check length first?
            if (s.length() != t.length())
                return false;

            int counter[26] = {0};

            // Hash map, this is using lowercase only
            for(int i = 0; i < s.length(); i++)
            {
                counter[s[i] - 'a']++;
                counter[t[i] - 'a']--;
            }

            for(auto count : counter)
                if (count != 0)
                    return false;

            return true;
        }
};