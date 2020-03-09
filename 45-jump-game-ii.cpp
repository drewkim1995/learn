// https://leetcode.com/problems/jump-game-ii/

class Solution
{
    public:
        int jump(vector<int> & nums)
        {
            int n = nums.size();
            if(n == 0)
                return 0;

            // maxReachPos indicates the farthest reachable position.
            int maxReachPos = nums[0];

            // curMaxReachPos indicates the current farthest reachable position.
            int curMaxReachPos = nums[0];

            int curStep = 1;
            for(int i = 1; i <= min(n-1, maxReachPos); i++)
            {
                curMaxReachPos = max(curMaxReachPos, i + nums[i]);

                // Returns min step
                if(i == n - 1)
                    return curStep;

                if(i == maxReachPos)
                {
                    maxReachPos = curMaxReachPos;
                    curStep++;
                }
            }
            return 0;
        }
};