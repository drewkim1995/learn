// https://leetcode.com/problems/divide-two-integers/

class Solution
{
    public:
        int divide(double dividend, double divisor)
        {
            if (dividend < INT_MIN || dividend > INT_MAX)
                return INT_MAX;
            if (divisor < INT_MIN || divisor > INT_MAX)
                return INT_MAX;

            bool convert = false;

            if (dividend < 0 && divisor < 0)
            {
                dividend = ~(int) dividend;
                divisor = ~(int) divisor;
                // To prevent error of overflow int type cast
                dividend++;
                divisor++;
            }
            else if (dividend < 0)
            {
                convert = true;
                dividend = ~(int) dividend;
                // To prevent error of overflow int type cast
                dividend++;
            }
            else if (divisor < 0)
            {
                convert = true;
                divisor = ~(int) divisor;
                // To prevent error of overflow int type cast
                divisor++;
            }

            double result = 0;
            double temp = dividend;
            double origDivisor = divisor;
            int shift = 0;

            // Shortening the while loop by using 'mult'/'div' by 2
            // Unsigned is okay at this point due to previous conversion
            while (((uint)divisor << shift) < ((uint)dividend >> shift))
                shift++;
            divisor = (uint)divisor << shift;

            while (temp - divisor >= 0)
            {
                temp = temp - divisor;
                result++;
            }

            // 'Reverse' the shift from before
            result = (int)result << shift;

            // Do the original divisor off the remainder(variable temp)
            while (temp - origDivisor >= 0)
            {
                temp = temp - origDivisor;
                result++;
            }

            // Convert back to negative if necessary
            if (convert)
            {
                result = ~(int) result;
                // To prevent error of overflow int type cast
                result++;
            }
            // Somehow we got negative number when it was supposed to be positive
            // e.g. test cases:
            // -2147483648
            // -1
            else if (result < 0)
                return INT_MAX;

            if ((int)result < INT_MIN || (int)result > INT_MAX)
                return INT_MAX;

            return result;
        }
};