class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() , ind = 0;
        //if(n==1)return 1;
        for(int i=0;i<n-1;i++){
             if(nums[i]!=nums[i+1]){
                 nums[ind++] = nums[i];
             }
        }
         nums[ind++] = nums[n-1];
        return ind;
    }
};