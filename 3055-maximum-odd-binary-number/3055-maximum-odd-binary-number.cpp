class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0 , n  = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
            s[i] = '0';
        }
        
        s[n-1]='1';cnt--;
        for(int i=0;i<s.size();i++){
            if(cnt==0)break;
            
                cnt--;
                s[i] = '1';
            
        }
        return s;
    }
};