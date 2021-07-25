// https://leetcode.com/problems/regular-expression-matching/

class Solution
{
    public:
        bool isMatch(string & s, string & p)
        {
            return subMatch(s, 0, p, 0);
        }

        bool subMatch(string & s, int sOff, string & p, int pOff)
        {
            // Pattern must match entire String
            if (pOff >= p.length())
            {
                if (sOff >= s.length())
                    return true;
                else
                    return false;
            }
            /* Continue working Pattern
            else if (sOff == s.length())
            {
                if (pOff == p.length()-1 && p[pOff] == '*')
                    return true;
                return false;
            }*/

            // Matches any single character
            if (p[pOff] == '.')
            {
                // Special Case: Zero or more of any character (".*")
                if (pOff + 1 < p.length() && p[pOff+1] == '*')
                {
                    // If this the end of the pattern, auto return true
                    if (pOff+1 == p.length()-1)
                        return true;

                    // Need to match all possible cases
                    /* Examples:
                    s = "ab"  |  p = ".*c"
                    s = "abc" |  p = ".*c"  */
                    for (int off = sOff; off <= s.length(); off++)
                    {
                        if (subMatch(s, off, p, pOff+2))
                            return true;
                    }
                    return false;
                }
                else
                {
                    if (sOff < s.length())
                        return subMatch(s, ++sOff, p, ++pOff);
                    else
                        return false;
                }

            }
            // Matches zero or more of the preceding element
            else if (p[pOff] == '*')
            {
                if (pOff > 0 && p[pOff-1] == s[sOff])
                {
                    // Test for '0' case
                    if (subMatch(s, sOff, p, pOff+1))
                        return true;

                    // Need to match all possible cases
                    for (int off = sOff; off < s.length(); off++)
                    {
                        if (p[pOff-1] != s[off])
                            return false;
                        if (subMatch(s, off+1, p, pOff+1))
                            return true;
                    }
                    return false;
                }
                else
                    return subMatch(s, sOff, p, ++pOff);
            }
            // Matches Character
            else if (sOff < s.length() && p[pOff] == s[sOff])
            {
                // Let next iteration manage it
                if (pOff+1 < p.length() && p[pOff+1] == '*')
                    return subMatch(s, sOff, p, ++pOff);
                else
                    return subMatch(s, ++sOff, p, ++pOff);
            }
            // Doesn't match but next is '*' | So it is "0 of the preceding element"
            else if (pOff+1 < p.length() && p[pOff+1] == '*')
                return subMatch(s, sOff, p, pOff+=2);

            return false;
        }
};