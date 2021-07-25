// https://leetcode.com/problems/roman-to-integer/

class Solution
{
    public:
        int romanToInt(string& s)
        {
            int ret = 0;
            int lastIndex = s.length() - 1;

            for (int i = 0; i < s.length(); i++)
            {
                switch (s[i])
                {
                    case 'I':
                        // Check for 4/9
                        if (i != lastIndex)
                        {
                            if (s[i+1] == 'V')
                            {
                                ret += 4;
                                i++;
                            }
                            else if (s[i+1] == 'X')
                            {
                                ret += 9;
                                i++;
                            }
                            else
                                ret += 1;
                        }
                        else
                            ret += 1;
                        break;
                    case 'V':
                        ret += 5;
                        break;
                    case 'X':
                        // Check for 40/90
                        if (i != lastIndex)
                        {
                            if (s[i+1] == 'L')
                            {
                                ret += 40;
                                i++;
                            }
                            else if (s[i+1] == 'C')
                            {
                                ret += 90;
                                i++;
                            }
                            else
                                ret += 10;
                        }
                        else
                            ret += 10;
                        break;
                    case 'L':
                        ret += 50;
                        break;
                    case 'C':
                         // Check for 400/900
                        if (i != lastIndex)
                        {
                            if (s[i+1] == 'D')
                            {
                                ret += 400;
                                i++;
                            }
                            else if (s[i+1] == 'M')
                            {
                                ret += 900;
                                i++;
                            }
                            else
                                ret += 100;
                        }
                        else
                            ret += 100;
                        break;
                    case 'D':
                        ret += 500;
                        break;
                    case 'M':
                        ret += 1000;
                        break;
                }
            }

            return ret;
        }
};