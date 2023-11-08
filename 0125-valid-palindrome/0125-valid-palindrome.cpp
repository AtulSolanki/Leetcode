class Solution {
public:
   bool isPalindrome(string s) {
        if (s.empty()) return true; 
        int z = s.size();
        int i = 0;
        while (i < z) {
            // cout << "comparing : " << s[i] << " and " << s[z] << endl;
            if (!isalnum(s[z])) { z--; continue; }
            if (!isalnum(s[i])) { i++; continue; }   
            if (tolower(s[i++]) != tolower(s[z--])) return false;
        }
        return true;
    }
    
};