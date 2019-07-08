class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            for (int iter = 0; iter < nums.size(); iter++)
            {
                for (int iter2 = iter + 1; iter2 < nums.size(); iter2++)
                {
                    //cout << nums.at(iter) << "+" << nums.at(iter2) << "=" << target << endl;
                    if (nums.at(iter) + nums.at(iter2) == target)
                        return vector<int> {iter, iter2};
                }
            }
            vector<int> retVal;
            return retVal;
        }
};