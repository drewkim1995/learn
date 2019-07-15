// https://leetcode.com/problems/climbing-stairs/

class Solution
{
    public:
        int climbStairs(int n)
        {
            int first = 1;
            int second = 2;

            if (n == 1)
                return first;
            else if (n == 2)
                return second;

            for (int i = 3; i <= n; i++)
            {
                int third = first + second;
                first = second;
                second = third;
            }

            return second;
        }
};