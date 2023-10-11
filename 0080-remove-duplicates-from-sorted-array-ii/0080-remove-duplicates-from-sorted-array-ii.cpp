class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size() , ind = 0 ,i=0;
         if(n<=2)return n;
        while(i<n){
            cout << nums[ind] << endl;
            nums[ind++] = nums[i++];
            int c =0;
            if(i==n)return ind;
            if(i<n-1 && nums[i]!=nums[i-1])continue;
             while(i<n-1 && nums[i]==nums[i+1]){
                 //nums[ind++] = nums[i++];
                 i++;
                 c++;
             }
             if(nums[i-1]==nums[i] || c>0)nums[ind++] = nums[i++];
             
        }
        // nums[ind++] = nums[n-1];
        return ind;
    }
};