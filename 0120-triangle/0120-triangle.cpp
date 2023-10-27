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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,a,dp);
    }
};