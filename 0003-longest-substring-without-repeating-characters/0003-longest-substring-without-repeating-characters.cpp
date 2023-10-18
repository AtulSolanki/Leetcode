class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //unordered_map<char,int>mp;
        vector<int>mp(256,-1);
        int l =-1,ans = 0,n = s.size();
        for(int i=0;i<n;i++){
           if(mp[s[i]]!=-1){
                 l = max(l,mp[s[i]]);
           }
            ans = max(ans,i-l); 
           mp[s[i]] = i;
        }
        return ans;
    }
};