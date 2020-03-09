// https://leetcode.com/problems/jump-game-ii/

class Solution
{
    private:
        unordered_map<int, int> jumpMap;

        int calcJump(vector<int>& nums, int pos, int count)
        {
            int size = nums.size()-1;
            if (pos == size)
                return count;
            else if (pos > size)
                return INT_MAX;

            int lowestCount = INT_MAX;

            //cout << "nums[" << pos << "] = " << nums[pos] << " | size-pos = " << size-pos << endl;
            // Best case would exit here with 1 jump
            if (nums[pos] > size-pos)
            {
                jumpMap[pos] = count + 1;
                return count+1;
            }

            for (int i = min(nums[pos], size-pos); i > 0; i--)
            //for (int i = 1; i <= min(nums[pos], size-pos); i++)
            {
                // Not in map yet
                if (jumpMap[pos+i] == 0)
                    jumpMap[pos+i] = calcJump(nums, pos + i, 1);

                //cout << "jumpMap[" << pos+i << "] = " << jumpMap[pos+i] << endl;

                if (jumpMap[pos+i] != INT_MAX && jumpMap[pos+i] + count < lowestCount)
                    lowestCount = jumpMap[pos+i] + count;

                // 2nd Best case is 2 jumps
                if (lowestCount == 2)
                    break;
            }
            return lowestCount;
        }
    public:
        int jump(vector<int>& nums)
        {
            return calcJump(nums, 0, 0);
        }
};