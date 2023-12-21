class Solution {
public:
    void profit_calc(vector<int>&prices,int i,int&mini,int&profit){
        if(i == prices.size()){
            return;
        }
        if(prices[i]<mini) mini=prices[i];
        
        int todays_profit=prices[i]-mini;
        
        if(todays_profit>profit){
            profit=todays_profit;
        }
        profit_calc(prices,i+1,mini,profit);
    }
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int profit=INT_MIN;
        profit_calc(prices,0,mini,profit);
        return profit;
    }
};

