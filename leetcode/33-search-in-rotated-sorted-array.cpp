// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
    public:
        int search(vector<int>& nums, int target)
        {
            const int count = nums.size();

            if (count == 0)
                return -1;

            int left = 0;
            int right = (count-1);

            while (left <= right)
            {
                int mid = (left + right) / 2;

                // The rightmost number of the second sub-array is smaller than the leftmost
                // number of the first sub-array if there exists and rotated position

                if (nums[mid] == target)
                    return mid;
                else if(nums[mid] > nums[right])
                {
                    if(target > nums[mid] || target <= nums[right])
                        left = mid + 1;     // condition for pick right side
                    else
                        right = mid - 1;    // else, pick left side
                }
                else
                {
                    if(target <= nums[right] && target > nums[mid])
                        left = mid + 1;     // condition for pick right side
                    else
                        right = mid - 1;    // else, pick left side
                }
            }

            return -1;
        }
};