class Solution {
public:
    int solve(vector<vector<int>>grid,int i,int j, vector<vector<int>>&dp){
        int n = grid.size() , m = grid[0].size();
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int d = grid[i][j] + solve(grid,i-1,j,dp);
        int r = grid[i][j] + solve(grid,i,j-1,dp);
        return dp[i][j] = min(d,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        //return solve(grid,n-1,m-1,dp);
        //dp[0][0] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d = 1e9 , r = 1e9;
                if(i==0 && j==0){dp[i][j] = grid[i][j];continue;}
                if(i>0) d = grid[i][j] + dp[i-1][j];
                if(j>0) r = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(d,r);
               // cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        return dp[n-1][m-1];
    }
};