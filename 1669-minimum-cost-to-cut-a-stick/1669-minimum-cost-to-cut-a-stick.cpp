class Solution {
public:
    int solve(int i,int j,vector<int>& cut,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long int mini = 1e9;
        for(int k=i;k<=j;k++){
                long long int cost =  cut[j+1] - cut[i-1] + solve(i,k-1,cut,dp) + solve(k+1,j,cut,dp);
                mini = min(mini,cost);
            
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int n1 = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        vector<vector<int>>dp(n1+2,vector<int>(n1+2,0));
        n = cuts.size();
        //return solve(1,n1,cuts,dp);

        for(int i=n1;i>=1;i--){
            for(int j=i;j<=n1;j++){
                long long int mini = 1e9;
                for(int k=i;k<=j;k++){
                long long int cost =  cuts[j+1] - cuts[i-1] + dp[i][k-1]+ dp[k+1][j];
                mini = min(mini,cost);
            
               }
             dp[i][j] = mini;
            }
        }
        return dp[1][n1];
    }
};