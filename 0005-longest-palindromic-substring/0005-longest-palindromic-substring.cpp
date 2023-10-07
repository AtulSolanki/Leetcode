class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        int k=2,ans=2,j,idx1,idx2;
        string str;
        if(n==1)return s;
        for(int i=0;i<n;i++){dp[i][i]=1;
                       str = s.substr(i,1); }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){dp[i][i+1]=1;
                    str = s.substr(i,2);}
        }
        while(k!=n){
            for(int i=0;i<n-k;i++){
                j=k+i;
                if(dp[i+1][j-1]==1 && s[i]==s[j]){
                    dp[i][j]=1;
                   
                    if(ans<=(j-i+1)){
                        ans= j-i+1;
                        idx1=j;
                        idx2=i;
                    }
                    
                }
            
            }
            k++;
        }
        if(ans==2)return str;
        str = s.substr(idx2,idx1-idx2+1);
        return str;
    }
};