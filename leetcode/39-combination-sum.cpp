// https://leetcode.com/problems/combination-sum/

class Solution
{
    private:
        vector<vector<int>> ret;

        void combo(vector<int> &candidates, vector<int> &theory, int tailIndex, int target)
        {
            target = target - candidates[tailIndex];
            if (target == 0)
            {
                theory.push_back(candidates[tailIndex]);
                ret.push_back(theory);
                theory.pop_back();
                return;
            }
            // Testing against smallest possible number
            else if (target < candidates[0] || target < 0)
                return;

            // Still possible combinations
            theory.push_back(candidates[tailIndex]);

            for (tailIndex; tailIndex >= 0; tailIndex--)
                combo(candidates, theory, tailIndex, target);

            theory.pop_back();
            return;
        }

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target)
        {
            // Empty case
            if (candidates.size() == 0)
                return ret;

            // Sort the array
            sort (candidates.begin(), candidates.end());

            // Easier to work in reverse as the vector size will grow in reverse
            for (int tailIndex = candidates.size()-1; tailIndex >= 0; tailIndex--)
            {
                if (candidates[tailIndex] > target)
                    continue;
                else if (candidates[tailIndex] == target)
                    ret.push_back(vector<int> {candidates[tailIndex]});
                else
                {
                    vector<int> theory;
                    combo(candidates, theory, tailIndex, target);
                }
            }

            return ret;

        }
};