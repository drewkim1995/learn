// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lowest = INT_MAX;

        int count = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];

            if (count >= target) {
                do {
                    if (count - nums[start] < target)
                        break;
                    count -= nums[start];
                } while (i != ++start);

                int len = i - start + 1;
                if (len < lowest)
                    lowest = len;
            }
        }

        return (lowest == INT_MAX) ? 0 : lowest;
    }
};