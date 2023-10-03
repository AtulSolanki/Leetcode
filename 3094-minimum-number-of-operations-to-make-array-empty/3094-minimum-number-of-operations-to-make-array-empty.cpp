class Solution {
public:
    int minOperations(vector<int>& nums) {
         int n = nums.size();
         unordered_map<int,int>mp;
         for(int i=0;i<n;i++){
             mp[nums[i]]++;
         }
        int ans =0;
         for(auto x:mp){
            if(x.second > 1){
                ans += (x.second+2)/3;
            }
            else  return -1;
         }
        return ans;
    }
};