/*
    1 <= minutes <= customers.length == grumpy.length <= 20000
    0 <= customers[i] <= 1000
    0 <= grumpy[i] <= 1
*/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfiedCount = 0;
        int customerSize = customers.size();

        // Start with group from index 0
        int len = min(customerSize, minutes);
        int unhappyCount = 0;
        for (int i = 0; i < len; ++i) {
            if (grumpy[i])
                unhappyCount += customers[i];
            else
                satisfiedCount += customers[i];

        }

        // Find the largest unhappy customer group
        int highestStartIndex = 0;
        int highestCount = unhappyCount;

        for (int i = 0; i + len < customerSize; ++i) {
            int oldVal = grumpy[i] ? customers[i] : 0;
            int newVal = grumpy[i+len] ? customers[i+len] : 0;
            if (!newVal)
                satisfiedCount += customers[i+len];

            unhappyCount += newVal - oldVal;
            if (unhappyCount > highestCount) {
                highestCount = unhappyCount;
                highestStartIndex = i+1;
            }
        }

        // Add the converted 'unhappy' customers
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i+highestStartIndex])
                satisfiedCount += customers[i+highestStartIndex];
        }

        return satisfiedCount;
    }
};