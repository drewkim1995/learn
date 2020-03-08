// https://leetcode.com/problems/group-anagrams/

class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            vector<vector<string>> ret;
            unordered_map<string, vector<string>> mymap;

            for (auto s : strs)
            {
                string key = s;
                sort(key.begin(), key.end());

                // Find in Map
                mymap[key].push_back(s);
            }

            for (auto v : mymap)
                ret.push_back(v.second);

            return ret;
        }
};