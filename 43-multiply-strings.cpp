// https://leetcode.com/problems/multiply-strings/
/*
  12
  12
----
  24
 120
=144


   123
   456
------
   738
  6150
 49200
=56088
*/

class Solution
{
    public:
        string multiply(const string & num1, const string & num2)
        {
            string ret = "";

            const string * sml = &num1;
            const string * lrg = &num2;

            if (num1 == "0" || num2 == "0")
                return "0";

            // Order of loops is important for the carrying
            if (sml->size() > lrg->size())
            {
                sml = &num2;
                lrg = &num1;
            }

            int loopCount = 0;

            for (int i = sml->size()-1; i >= 0; i--, loopCount++)
            {
                string line = "";
                char v1 = (*sml)[i] - '0';
                char carry = 0;

                for (int j = lrg->size()-1; j >= 0; j--)
                {
                    char v2 = v1 * ((*lrg)[j] - '0') + carry;
                    carry = v2 / 10;
                    v2 = (v2 % 10) + '0';
                    line.insert(0, 1, v2);  // Prepend one char
                }

                if (carry > 0)
                    line.insert(0, 1, carry + '0');

                // Offset each line by 10's
                for (int offset = 0; offset < loopCount; offset++)
                    line.push_back('0');
                ret = add(ret, line);
            }

            return ret;
        }

        string add(const string & num1, const string & num2)
        {
            string ret = "";
            char carry = 0;
            int index = 0;
            int size1 = num1.size()-1;
            int size2 = num2.size()-1;

            for (; index <= size1; index++)
            {
                char v1 = num1[size1 - index] - '0';
                char v2 = v1 + (num2[size2 - index] - '0') + carry;
                carry = v2 / 10;
                v2 = (v2 % 10) + '0';
                ret.insert(0, 1, v2);  // Prepend one char
            }

            // Copy from where small left off
            for (; index <= size2; index++)
            {
                char v2 = (num2[size2 - index] - '0') + carry;
                carry = v2 / 10;
                v2 = (v2 % 10) + '0';
                ret.insert(0, 1, v2);  // Prepend one char
            }

            if (carry > 0)
                ret.insert(0, 1, carry + '0');

            return ret;
        }
};