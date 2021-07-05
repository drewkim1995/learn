// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int count = 0;
        int size = nums.size();

        if (size == 0) return;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                ++count;
            } else {
                nums[index++] = nums[i];
            }
        }

        for (index; index < size; ++index) {
            nums[index] = 0;
        }
    }
};