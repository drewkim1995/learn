// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution
{
    private:
        unordered_map<char, vector<char>> letterMap;

    public:
        vector<string> letterCombinations(string & digits)
        {
            if (digits.length() == 0)
                return {};

            letterMap['2'] = {'a','b','c'};
            letterMap['3'] = {'d','e','f'};
            letterMap['4'] = {'g','h','i'};
            letterMap['5'] = {'j','k','l'};
            letterMap['6'] = {'m','n','o'};
            letterMap['7'] = {'p','q','r','s'};
            letterMap['8'] = {'t','u','v'};
            letterMap['9'] = {'w','x','y','z'};

            vector<string> ret;

            for (auto d : digits)
            {
                ret = combine(ret, letterMap[d]);
            }

            return ret;
        }
        template <class T>
        vector<string> combine(const T & input1, const vector<char> & input2)
        {
            vector<string> combined;

            if (input1.size() == 0)
            {
                for (auto in2 : input2)
                    combined.push_back(string(1,in2));
            }

            for (auto in1 : input1)
            {
                for (auto in2 : input2)
                {
                    combined.push_back(in1 + in2);
                }
            }
            return combined;
        }
};