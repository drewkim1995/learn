// https://leetcode.com/problems/integer-to-roman/

class Solution
{
    public:
        string intToRoman(int & num)
        {
            string roman;

            if (num > 0)
            {
                // Process Thousands first
                thousands(num, roman);
                hundreds(num, roman);
                tens(num, roman);
                ones(num, roman);
            }

            return roman;
        }

        void thousands(int & num, string & str)
        {
            for (int i = 0; i < num / 1000; i++)
                str += "M";
            num %= 1000;
        }

        void hundreds(int & num, string & str)
        {
            int h = num / 100;
            num %= 100;

            if (h == 4)
            {
                 str += "CD";
                return;
            }
            else if (h == 9)
            {
                str += "CM";
                return;
            }
            else if (h > 4 && h < 9)
            {
                str += "D";
                h -= 5;
            }

            for (int i = 0; i < h; i++)
                str += "C";
        }

        void tens(int & num, string & str)
        {
            int t = num / 10;
            num %= 10;

            if (t == 4)
            {
                 str += "XL";
                return;
            }
            else if (t == 9)
            {
                str += "XC";
                return;
            }
            else if (t > 4 && t < 9)
            {
                str += "L";
                t -= 5;
            }

            for (int i = 0; i < t; i++)
                str += "X";
        }

        void ones(int & o, string & str)
        {
            if (o == 4)
            {
                 str += "IV";
                return;
            }
            else if (o == 9)
            {
                str += "IX";
                return;
            }
            else if (o > 4 && o < 9)
            {
                str += "V";
                o -= 5;
            }

            for (int i = 0; i < o; i++)
                str += "I";
        }
};