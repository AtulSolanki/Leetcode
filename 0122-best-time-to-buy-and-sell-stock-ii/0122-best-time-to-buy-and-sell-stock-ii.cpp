class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0 , mini = prices[0];
        int n = prices.size();
        for(int i=1;i<n;i++){
           if(prices[i]>prices[i-1]){
               ans += prices[i]-prices[i-1];
           }
        //    if(prices[i]>mini){
        //        ans += prices[i]-mini;
        //        mini = prices[i];
        //    }
        //    else mini = min(mini,prices)
        }
        return ans;
    }
};