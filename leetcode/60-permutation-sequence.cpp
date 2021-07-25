// https://leetcode.com/problems/permutation-sequence/

class Solution
{
    public:
        string getPermutation(int n, int k)
        {
            // Factorial Tables from 0! to 10!
            int pTable[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

            // Preload vector, could be better with n digits instead
            vector<char> numSet{'1', '2', '3', '4', '5', '6', '7', '8', '9'};

            string result;

            // Note this is O(n^2) because of vector.erase() will always create
            // a new vector array and copy orig value to it except erased one.
            while(n > 0)
            {
                int temp = (k - 1) / pTable[n - 1];
                result += numSet[temp];
                numSet.erase(numSet.begin() + temp);
                k = k - temp * pTable[n - 1];

                cout << "n=" << n << " | k=" << k << " | temp=" << temp << " | res=" << result << " | sizeof numset=" << numSet.size() << endl;

                n--;
            }
            return result;
        }
};