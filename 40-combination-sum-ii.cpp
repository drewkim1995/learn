// https://leetcode.com/problems/combination-sum-ii/

class Solution
{
    public:
        vector<vector<int>> combinationSum2(vector<int> & candidates, int target)
        {
            sort(candidates.begin(), candidates.end());
            recurse(candidates, candidates.size(), 0, target);
            return result;
        }
    private:
        vector<int> theory;
        vector<vector<int>> result;
        void recurse(const vector<int> & candidates, const int size, int start, int target)
        {
            if (target == 0)
            {
                result.push_back(theory);
                return;
            }

            int index = start;
            while (index < size && target-candidates[index] >= 0)
            {
                if (index == start || candidates[index] != candidates[index-1])
                {
                    theory.push_back(candidates[index]);
                    recurse(candidates, size, index+1, target-candidates[index]);
                    theory.pop_back();
                }
                index++;
            }
        }
};