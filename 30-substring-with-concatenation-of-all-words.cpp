// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution
{
    public:
        vector<int> findSubstring(string& s, vector<string>& words)
        {
            if (s.empty() || words.empty())
                return {};

            const int wordLength = words[0].length();
            vector<int> ret;
            int lastIndex = s.length() - ((words.size() - 1) * wordLength);

            sort (words.begin(), words.end());

            // Iterate through each letter until there are less characters than the total in words
            for (int startIndex = 0; startIndex < lastIndex; startIndex++)
            {
                int count = 0;
                vector<string> temp;

                // Build a vector of strings to compare against
                for (int i = 0; i < (words.size() * wordLength); i+= wordLength)
                {
                    string sub = s.substr(startIndex + i, wordLength);
                    //cout << sub << " ";
                    temp.push_back(sub);
                }
                //cout << endl;

                sort (temp.begin(), temp.end());

                // Compare both sorted vectors for a match
                for (int i = 0; i < words.size(); i++)
                {
                    if (temp[i] == words[i])
                        count++;
                    else
                        break;
                }

                // Store the index if sorted vectors match
                if (count == words.size())
                    ret.push_back(startIndex);
            }

            return ret;
        }
};