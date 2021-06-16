// problem link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,minp=prices[0];
        for(int i=1;i<prices.size();i++){
            profit = max(profit,prices[i]-minp);
            minp = min(prices[i],minp);
        }
        return profit;
    }
};


// time -> O(n)
// space -> O(1)