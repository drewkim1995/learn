// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);

        for (int i = 0; i < size; ++i) {
            int sum = 0;
            int num = nums[i];

            if (i != 0 && num == nums[i-1])
                result[i] = result[i-1];
            else {
                for (int j = 0; j < size; j++) {
                    sum += num > nums[j] ? num - nums[j] : nums[j] - num;
                }
                result[i] = sum;
            }
        }


        return result;
    }
};