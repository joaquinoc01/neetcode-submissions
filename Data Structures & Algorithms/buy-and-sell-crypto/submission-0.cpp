class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min = prices[0];
        int diff = 0;

        for (size_t i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < min)
            {
                min = prices[i];
            }
            else if (prices[i] > min)
            {
                if ((prices[i] - min) > diff)
                    diff = prices[i] - min;
            }
        }
        return diff;
    }
};
