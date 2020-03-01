// https://leetcode.com/problems/count-and-say/

class Solution
{
    public:
        string countAndSay(int n)
        {
            // For n = 1, result = "1"
            if (n < 2)
                return "1";

            // For n = 2, result = "11"
            string result = "11";

            for (int loop = 2; loop < n; loop++)
            {
                string temp = "";
                char value = result[0];
                int freq = 1;

                for (int index = 1; index < result.length(); index++)
                {
                    if (result[index] == value)
                        freq++;
                    else
                    {
                        temp.append(to_string(freq) + value);
                        freq = 1;
                        value = result[index];
                    }
                }

                temp.append(to_string(freq) + value);
                result = temp;
            }

            return result;
        }
};