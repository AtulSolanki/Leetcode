class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0 , n = nums.size();
        for(int j=0;j<n;j++){
           if(nums[j]!=0){
               nums[i++] = nums[j];
           }
        }
        while(i<n){
            nums[i++] = 0;
        }
    }
};