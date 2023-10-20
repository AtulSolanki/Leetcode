class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long ans =0;
        const int mod = 1e9+7;
        for(int i=1;i<=target/2;i++){
             ans += i;
             n--;
             if(n==0)break;
        }
        ans = (ans+ ((long long)target*n) + ((long long)(n-1)*n)/2 )%mod;
        return ans; 
    }
};