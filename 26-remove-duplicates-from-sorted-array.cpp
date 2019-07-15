https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
    public:
        int removeDuplicates(vector<int>& nums)
        {
            if (nums.size() < 1)
                return 0;

            int count = 1;
            int prev = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] != prev)
                {
                    if (i != count)
                        nums[count] = nums[i];
                    count++;
                }

                prev = nums[i];
            }

            return count;
        }
};