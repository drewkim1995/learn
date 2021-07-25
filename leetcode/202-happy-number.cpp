// https://leetcode.com/problems/happy-number/

class Solution
{
    public:
        bool isHappy(int n)
        {
            unordered_map<int, int> used;

            while (n != 1)
            {
                if (used[n]++ > 0)
                    return false;

                string in = to_string(n);

                n = 0;

                for (int i = 0; i < in.length(); ++i)
                    n += (in[i] - 0x30) * (in[i] - 0x30);
            }

            return true;
        }
};