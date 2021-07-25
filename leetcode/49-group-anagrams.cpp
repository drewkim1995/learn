// https://leetcode.com/problems/group-anagrams/

class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs)
        {
            unordered_map<string, int>  indices;
            vector<vector<string>>      result;

            for (auto s : strs)
            {
                string key = s;
                sort(key.begin(), key.end());

                // Unordered map has no dupes, count is 1 if found or 0 if not
                if (indices.count(key))
                    result[indices[key]].push_back(s);
                else
                {
                    result.push_back(vector<string>(1, s));
                    indices[key] = result.size() - 1;
                }
            }

            return result;
        }
};