class Solution {
public:
    int solve(vector<vector<int>>& v, int i, int j, vector<vector<int>>&dp){
        int n = v.size();
        int m = v[0].size();
        if( i>=n || j>=m || v[i][j] == 1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1 && j==m-1)return 1;
        return dp[i][j] = solve(v,i+1,j,dp) + solve(v,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
           int n = v.size();
           int m = v[0].size();
           vector<vector<int>>dp(n,vector<int>(m,-1));
            return solve(v,0,0,dp);
    }
};