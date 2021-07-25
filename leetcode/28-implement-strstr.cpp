// https://leetcode.com/problems/implement-strstr/

class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            if (needle.empty())
                return 0;

            int ret = -1;

            for (int i = 0; i < haystack.size(); i++)
            {
                if (needle.size() > haystack.size() - i)
                    break;

                if (haystack[i] != needle[0])
                    continue;

                int match = 1;
                for (int j = 1; j < needle.size(); j++)
                {
                    if (haystack[i+j] == needle[j])
                        match++;
                    else
                        break;
                }

                if (match == needle.size())
                    return i;

            }

            return ret;
        }
};