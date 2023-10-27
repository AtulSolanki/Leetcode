class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(),l=0,r=0,ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')l++;
            else r++;
            if(r>l){
                r--;
                ans++;
            }
            if(l==r){
                l = 0;
                r = 0;
            }
            
        }
        if(l>r)ans += (l-r);
        return ans;
    }
};