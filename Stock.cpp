class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int buy_flag = 0;
        int sell = 0;
        int profit = 0;
        int n = prices.size();
        if(n==0 || n==1)
            return 0;
        if(prices[1]>=prices[0]){
            buy = prices[0];
            buy_flag = 1;
        }
        for(int i = 1;i<n-1;i++){
            if(prices[i]<=prices[i-1] && prices[i]<=prices[i+1] && buy_flag == 0){
                buy = prices[i];
                buy_flag = 1;
            } 
            if(prices[i]>=prices[i-1] && prices[i]>=prices[i+1] && buy_flag == 1){
                sell = prices[i];
                profit = profit + sell - buy;
                buy_flag = 0;
            }
        }
        if(prices[n-1]>=prices[n-2] && buy_flag == 1){
            profit = profit + prices[n-1] - buy;
        }
        return profit;
    }
};
