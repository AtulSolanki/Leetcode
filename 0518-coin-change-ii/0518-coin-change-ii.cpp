class Solution {
public:
   int ans = INT_MAX;
    int solve(int tar,  int ind, vector<int>arr, vector<vector<int>> &dp){
        if(tar == 0){
            //ans = min(ans,cnt);
            return 1;
        }
        if(tar < 0 || ind<0){
           return 0; 
        }
        if(dp[ind][tar] != -1)return dp[ind][tar];
        int pick = solve(tar-arr[ind], ind, arr,dp);
        int not_pick = solve(tar, ind-1, arr,dp);
        return dp[ind][tar] = pick + not_pick;
    }
    int change(int amount, vector<int>& arr) {
         int n = arr.size();
          vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
          return solve(amount,arr.size()-1,arr,dp);
    }
};