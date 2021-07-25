// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int length = prices.size();

        if (length < 2)
            return 0;
        else if (length == 2)
        {
            if (prices[0] >= prices[1])
                return 0;
            else
                return prices[1] - prices[0];
        }

        int buy = prices[0];
        int max = 0;

        for (int i = 1; i < length; i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            else if (max < prices[i] - buy)
                max = prices[i] - buy;
        }

        return max;
    }
};