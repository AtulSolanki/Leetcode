class Solution {
public:
    int helper(string& s, int i, int j) {
        if (i >= j) return 1;
        if(s[i]!=s[j])return 0;
        return helper(s, i+1, j-1);
    }
    int countSubstrings(string s) {
           int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = i; j < s.size(); ++j) {
                count += helper(s, i, j);
            }
        }
        return count;
    }
};