class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int>>freq(n+1,vector<int>(26,0));
        long long int ans = 0;
        freq[1][s[0]-'a'] = 1;
        for(int i=1;i<n;i++){
            freq[i+1][s[i]-'a'] = 1+freq[i][s[i]-'a'];
            for(int k=0;k<26;k++){
                 if(s[i]-'a' != k )freq[i+1][k] = freq[i][k];
    
            }
            
        }
        // for(int i=0;i<=n;i++){
        //     for(int k=0;k<26;k++)cout << freq[i][k] << " ";
        //     cout << endl;
        // }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mini = INT_MAX , maxi = INT_MIN; 
                for(int k=0;k<26;k++){
                    maxi = max(maxi,freq[j+1][k]-freq[i][k]);
                    if(freq[j+1][k]-freq[i][k]>=1)mini = min(mini,freq[j+1][k]-freq[i][k]);
                }
                //if(mini)
                ans += (maxi-mini);
            }
        }
        return ans;
    }
};