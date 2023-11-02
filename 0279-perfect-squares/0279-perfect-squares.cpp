class Solution {
public:
    int ans = INT_MAX;
    int solve(int tar, int cnt, int ind, vector<int>arr, vector<vector<int>> &dp){
        if(tar == 0){
            ans = min(ans,cnt);
            return 0;
        }
        if(tar < 0 || ind<0){
           return 1e9; 
        }
        if(dp[ind][tar] != -1)return dp[ind][tar];
        int pick = 1 + solve(tar-arr[ind], cnt+1, ind, arr,dp);
        int not_pick = 0 + solve(tar, cnt, ind-1, arr,dp);
        return dp[ind][tar] = min(pick, not_pick);
    }
    int numSquares(int n) {
        vector<int>arr;
        vector<vector<int>>dp(101,vector<int>(n+1));
        for(int i=1;i<=100;i++){
            arr.push_back(i*i);
        }
        //return solve(n,0,arr.size()-1,arr,dp);
        //return ans;
        int ind = arr.size(), tar = n;
        for(int i=0;i<ind;i++)dp[i][0] = 0;
        for(int i=1;i<=tar;i++)dp[0][i] = 1e9;
        for(int i=1;i<=ind;i++){
            for(int j=0; j<= tar;j++){
                int pick = 1e9;
                // if(j==0){
                //     dp[i][j] = 0;
                //     continue;
                // }
                // if(i==0 && j!=0){
                //     dp[i][j] = 1e9;
                //     continue;
                // }
                if(j>=arr[i-1])pick = 1 + dp[i][j-arr[i-1]];
                int not_pick = 0 + dp[i-1][j];
                dp[i][j] = min(pick, not_pick);
            }
        }
        return dp[ind-1][tar];
    }
};