class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r){
            while(l < r && !(s[l] >=  '0'  && s[l] <= '9') && !(s[l] >=  'A'  && s[l] <= 'Z') && !(s[l] >=  'a' && s[l] <= 'z')){
                 l++;
            }
            if(l<r && s[l] >= 'A' && s[l]<= 'Z'){
                s[l] += 32;
            }
            while(l < r && !(s[r] >=  '0'  && s[r] <= '9') && !(s[r] >=  'A'  && s[r] <= 'Z') && !(s[r] >=  'a' && s[r] <= 'z')){
                 r--;
            }
            if(l < r && s[r] >= 'A' && s[r] <= 'Z'){
                s[r] += 32;
            }
            if(l<r && s[l]!= s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    
};