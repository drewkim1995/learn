// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution
{
    public:
        int maxProfit(vector<int>& prices)
        {
        	/*
        	Much simpler solution found online

			  if(prices.size() <= 1) return 0;

			  int res = 0;

			  for( size_t i = 1; i < prices.size(); i++)
			    if( prices[i] - prices[i-1] > 0 )
			      res += prices[i] - prices[i-1];

			  return res;
        	*/
            int size = prices.size();

            if (size < 2)
                return 0;

            int boughtIndex = -1;
            int profit = 0;

            for (int i = 0; i < size; i++)
            {
                // Buying
                if (boughtIndex == -1)
                {
                    // Tomorrow cheaper than today (Except on last day)
                    if (i < size-1 && prices[i+1] < prices[i])
                        continue;
                    boughtIndex = i;
                    //cout << "bought[" << i << "] at $" << prices[i] << endl;
                }
                // Selling
                else
                {
                    // Tomorrow dearer than today (Except on last day)
                    if (i < size-1 && prices[i+1] > prices[i])
                        continue;
                    profit += prices[i] - prices[boughtIndex];
                    boughtIndex = -1;
                    //cout << "sold[" << i << "] at $" << prices[i] << endl;
                }
            }

            return profit;
        }
};