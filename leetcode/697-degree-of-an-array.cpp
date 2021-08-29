https://leetcode.com/problems/degree-of-an-array/

class Solution {
private:
    struct data {
        int count = 0;
        int first = 0;
        int last = 0;
    };
public:
    int findShortestSubArray(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, data> umap;

        // Get Frequency
        for (int i = 0; i < size; ++i) {
            int num = nums[i];
            if (umap[num].count++ == 0)
                umap[num].first = i;
            else
                umap[num].last = i;
        }

        int shortest = INT_MAX;
        int degree = 0;
        for (auto x : umap) {
            int len = 0;
            if (degree < x.second.count) {
                degree = x.second.count;
                if (degree == 1) len = 1;
                else len = x.second.last - x.second.first + 1;
                shortest = len;
            } else if (degree == x.second.count) {
                if (degree == 1) len = 1;
                else len = x.second.last - x.second.first + 1;

                if (len < shortest)
                    shortest = len;
            }
        }

        return shortest;
    }
};