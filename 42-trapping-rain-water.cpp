// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
    public:
    int trap(vector<int>& height)
    {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r)
        {
            //cout <<  "[" << l << "," << r;
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;

            //cout << "] lower = " << lower << " | level = " << level << " | water = " << water << endl;
        }
        return water;
    }
};