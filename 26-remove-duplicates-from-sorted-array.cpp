https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution
{
    public:
        int removeDuplicates(vector<int>& nums)
        {
            if (nums.size() < 1)
                return 0;

            int count = 0;

            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] != nums[count])
                {
                    count++;
                    nums[count] = nums[i];
                }
            }

            return count + 1;
        }
};