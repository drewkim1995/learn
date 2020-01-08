// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

// Found this solution and added some comments
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/

class Solution
{
    public:
        vector<int> findSubstring(string& s, vector<string>& words)
        {
            // Fringe Case
            if (s.empty() || words.empty())
                return {};

            // Record the expected times of each word
            unordered_map<string, int> counts;
            for (string word : words)
                counts[word]++;

            vector<int> indexes;
            int n = s.length();
            int num = words.size();
            int len = words[0].length();
            int lastIndex = n - (num * len) + 1;

            // Iterate each letter until there are less characters than the total in words
            for (int startIndex = 0; startIndex < lastIndex; startIndex++)
            {
                unordered_map<string, int> seen;
                int matchCount;

                // Iterate through strings to compare
                for (matchCount = 0; matchCount < num; matchCount++)
                {
                    string word = s.substr(startIndex + matchCount * len, len);

                    // Find the String
                    if (counts.find(word) != counts.end())
                    {
                        seen[word]++;

                        // More than expected, stop the check
                        if (seen[word] > counts[word])
                            break;
                    }
                    // Unexpected String, stop the check
                    else
                        break;
                }

                if (matchCount == num)
                    indexes.push_back(startIndex);
            }

            return indexes;
        }
};