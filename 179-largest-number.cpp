// https://leetcode.com/problems/largest-number/

class Solution
{
    public:
        static bool largest(int i, int j)
        {
            string ij = to_string(i) + to_string(j);
            string ji = to_string(j) + to_string(i);

            for (int iter = 0; iter < ij.length(); iter++)
            {
                if (ij[iter] != ji[iter])
                    return ij[iter] > ji[iter];
            }
            return false;

        }
        string largestNumber(vector<int>& nums)
        {
            string res = "";

            sort(nums.begin(), nums.end(), largest);

            for(auto x : nums)
            {
                if (res == "0" && x == 0)
                    continue;
                res += to_string(x);
            }

            return res;
        }
};