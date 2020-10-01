// https://leetcode.com/problems/largest-number/

class Solution
{
    public:
        static bool compare(string a, string b)
        {
            return a+b > b+a;
        }
        string largestNumber(vector<int>& nums)
        {
            vector<string> numbers;
            for (int n : nums)
                numbers.push_back(to_string(n));

            sort(numbers.begin(), numbers.end(), compare);

            string res = "";

            for(auto x : numbers)
                res += x;

            return res[0] == '0' ? "0" : res;
        }
};