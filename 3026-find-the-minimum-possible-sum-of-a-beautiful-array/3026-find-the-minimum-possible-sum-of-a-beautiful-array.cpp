class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long ans =0;
        const int mod = 1e9+7;
        set<int>st;
        //int i =1;
        for(int i=1;i<=target/2;i++){
             ans += i;
             n--;
             if(n==0)break;
        }
    //    while( n>0){
    //         if(st.find(target-i)== st.end()){
    //             st.insert(i); 
    //             ans = (ans + i)%mod;
    //              n--;
    //         }
            
    //        i++;
          
    //     }
        //cout<< ans << " "<< n << endl;
        ans = (ans+ ((long long)target*n) + ((long long)(n-1)*n)/2 )%mod;
        return ans; 
    }
};