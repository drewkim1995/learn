// https://leetcode.com/problems/plus-one/

class Solution
{
    public:
        vector<int> plusOne(vector<int>& digits)
        {
            int carry = 1;
            for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++)
            {
                *it = (*it + carry) % 10;

                if (*it != 0)
                {
                    carry = 0;
                    break;
                }
            }

            if (carry)
                digits.insert(digits.begin(), 1);

            return digits;
        }
};