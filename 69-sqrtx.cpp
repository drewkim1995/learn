// https://leetcode.com/problems/sqrtx/

class Solution
{
    public:
        int mySqrt(int x)
        {
            for (int i = 1; i <= (x/2) + 1; i++)
            {
                double sqre = (double) i * i;
                if (sqre == x)
                    return i;
                else if (sqre > x)
                    return i-1;
            }

            return 0;
        }
};