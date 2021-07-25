// https://leetcode.com/problems/single-number/

class Solution
{
    public:
        int singleNumber(vector<int>& nums)
        {
            int single = 0;

            /* XOR:
                If we take XOR of zero and some bit, it will return that bit.
                If we take XOR of two same bits, it will return 0.
            */
            for (auto i : nums)
                single ^= i;

            return single;
        }
};