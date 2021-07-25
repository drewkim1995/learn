// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
    public:
        string longestCommonPrefix(vector<string>& strs)
        {
            string ret = "";

            if (strs.size() == 1)
                return strs[0];
            else if (strs.size() > 1)
            {
                int smallest = strs[1].length();

                for (int i = 1; i < strs.size(); i++)
                {
                    if (strs[i].length() < smallest)
                        smallest = strs[i].length();
                }

                for (int i = 0; i < smallest; i++)
                {
                    int count = 0;
                    for (int j = 1; j < strs.size(); j++)
                    {
                        if (strs[j-1][i] == strs[j][i])
                            count++;
                    }
                    if (count == strs.size()-1)
                        ret += strs[0][i];
                    else
                        break;
                }
            }

            return ret;
        }
};