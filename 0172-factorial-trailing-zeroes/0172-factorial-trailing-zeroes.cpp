class Solution {
public:
    int trailingZeroes(int n) {
        int ans =0;
        int x = 5;
        while(true){
            int val = n/x;
            if(val==0)return ans;
            ans += val;
            x *= 5;
        }
    }
};