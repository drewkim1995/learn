https://leetcode.com/problems/3sum-closest/

class Solution
{
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {
            int size = nums.size();
            int closest = 0;

            if (size < 4)
            {
                for (int i = 0; i < size; i++)
                    closest += nums[i];
                return closest;
            }

            closest = nums[0] + nums[1] + nums[2];

            // Sort Input First
            sort(nums.begin(), nums.end());

            // Starting at Smallest number
            for (int i = 0; i < size - 2; i++)
            {
                // Testing the worst cases
                if (i > 0 && nums[i] == nums[i-1])
                    continue;   // Avoid duplicates thru 1st value

                int j = i + 1;      // Second value
                int k = size - 1;   // Third value

                while (j < k)
                {
                    // Remember we sorted the input!
                    int sum = nums[i] + nums[j] + nums[k];

                    if (abs(target-closest) > abs(target-sum))
                        closest = sum;

                    // Get a number smaller than current k
                    if (sum > target)
                        k--;
                    // Get a number larger than current j
                    else if (sum < target)
                        j++;
                    // Match
                    else
                        return sum;
                }
            }


            return closest;
        }
};