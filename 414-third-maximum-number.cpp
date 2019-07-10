// https://leetcode.com/problems/third-maximum-number/

class Solution
{
    private:
        queue<int> q;
    public:
        int thirdMax(vector<int>& nums)
        {
            int ret = 0;
            int size = nums.size();

            if (size == 1)
                return nums[0];
            else if (size == 2)
                return max(nums[0], nums[1]);
            else if (size > 2)
            {
                sort(nums.begin(), nums.end());

                int dupe = 0;
                q.push(nums[size-1]);

                for (vector<int>::reverse_iterator i = nums.rbegin() + 1; i != nums.rend(); i++)
                {
                    if (*i != q.back())
                        q.push(*i);

                    if (q.size() == 3)
                        return q.back();
                }

                if (q.size() > 0 /*&& q.size() < 3*/)
                    ret = q.front();
            }

            return ret;
        }
};