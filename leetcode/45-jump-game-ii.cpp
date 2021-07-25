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

                /* The idea is to constantly get the maximum reach
                   and by iterating through the array/vector.
                   We keep updating the current maximum through the
                   max func and 'commit' it when we reach the maxReach.
                   Finally we return the steps when we are at the
                   last index.

                cout << "i = " << i << " | "
                     << "nums[i] = " << nums[i] << " | "
                     << "cur = " << curMaxReachPos << " | "
                     << "max = " << maxReachPos << " | "
                     << "step = " << curStep << endl;
                 */
            }
            return 0;
        }
};