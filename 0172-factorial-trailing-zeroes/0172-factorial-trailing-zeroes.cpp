class Solution {
public:
    int trailingZeroes(int n) {
        int ans =0;
        int x = 5;
        while(n>=x){
            int val = n/x;
            ans += val;
            x *= 5;
        }
        return ans;
    }
};