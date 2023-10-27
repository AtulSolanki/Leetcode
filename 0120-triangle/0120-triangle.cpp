class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp){
        if(i==a.size()){
             return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int c1 = a[i][j] + solve(i+1, j, a,dp);
        int c2 = a[i][j] + solve(i+1, j+1, a,dp);
        return dp[i][j] = min(c1,c2);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>>dp(n,vector<int>(n));
        //return solve(0,0,a,dp);
        dp[0][0] = a[0][0];
        if(n==1)return a[0][0];
        int ans = 1e9;
        for(int i=1;i<n;i++){   
            for(int j=0;j<=i;j++){
                if(j==i){
                    dp[i][j] = a[i][j] + dp[i-1][j-1];
                    if(i==n-1)ans = min(ans,dp[i][j]);
                    continue;
                }
                int c1 = a[i][j] + dp[i-1][j];
                int c2 = 1e9;
                if(j>0)c2 = a[i][j] + dp[i-1][j-1];
                dp[i][j] = min(c1,c2);
               // cout << dp[i][j] << " ";
                if(i==n-1)ans = min(ans,dp[i][j]);
            }
            //cout << endl;
        }
        return ans;
    }
};