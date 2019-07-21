// https://leetcode.com/problems/add-binary/

class Solution
{
    public:
        string addBinary(string &a, string &b)
        {
            int aIndex = a.length() - 1;
            int bIndex = b.length() - 1;
            int carry = 0;
            string ret;

            while (aIndex >= 0 || bIndex >= 0)
            {
                int aChar = 0;
                int bChar = 0;
                int sum = 0;

                if (aIndex >= 0)
                    aChar = a[aIndex--] - '0';
                if (bIndex >= 0)
                    bChar = b[bIndex--] - '0';

                sum = aChar + bChar + carry;
                switch (sum)
                {
                    case 1:
                        ret.insert(0, "1");
                        carry = 0;
                        break;
                    case 2:
                        ret.insert(0, "0");
                        carry = 1;
                        break;
                    case 3:
                        ret.insert(0, "1");
                        carry = 1;
                        break;
                    default:
                        ret.insert(0, "0");
                        carry = 0;
                        break;
                }
            }

            if (carry != 0)
                ret.insert(0, "1");

            return ret;
        }
};