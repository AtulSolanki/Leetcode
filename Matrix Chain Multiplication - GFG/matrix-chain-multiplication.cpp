//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

   
class Solution{
public:
    int solve(int arr[], vector<vector<int>>&dp,int i,int j){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<j;k++){
             mini=min(mini,arr[i-1]*arr[k]*arr[j]+solve(arr,dp,i,k)+solve(arr,dp,k+1,j));
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int n, int arr[])
    {
       vector<vector<int>>dp(n,vector<int>(n));
         //return solve(arr,dp,1,n-1);
         for(int i=0;i<n;i++){
             dp[i][i] =0;
         }
         for(int i=n-1;i>=1;i--){
             for(int j=i+1;j<n;j++){
                 int mini = INT_MAX;
                for(int k=i;k<j;k++){
                    mini=min(mini,arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j]);
                 }
                 dp[i][j] = mini;
             }
            
         }
         return dp[1][n-1];
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends