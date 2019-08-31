// https://leetcode.com/problems/majority-element/

class Solution
{
    public:
        int majorityElement(vector<int>& nums)
        {
            map<int, int> elements;

            for (auto i : nums)
            {
                if (elements.count(i) == 0)
                    elements[i] = 1;
                else
                    elements[i]++;
            }

            int ret = 0;
            int count = 0;

            for (auto e : elements)
            {
                if (e.second > count)
                {
                    count = e.second;
                    ret = e.first;
                }
            }

            return ret;
        }
};