class Solution {
public:
    int countSubstrings(string s) {
          int n = s.size();
          vector<vector<bool>> dp(n,vector<bool>(n,false));
          int ans = 0;
          for(int len=0;len<n;len++){
              int i = 0;
              for(int j=i+len;j<n;j++,i++){
                  if(len==0) {
                      dp[i][j] = 1;
                  }
                  else if(len==1){
                      if(s[i]==s[j]) {
                          dp[i][j] = 1;
                      }
                  }
                  else{
                      if(s[i]==s[j] && dp[i+1][j-1]){
                          dp[i][j] = 1;
                      }
                  }
                  ans += dp[i][j];
              }
          }
          return ans;
    }
};