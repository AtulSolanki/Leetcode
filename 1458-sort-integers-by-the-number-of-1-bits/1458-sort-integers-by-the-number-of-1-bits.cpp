class Solution {
public:
    int bitCount (int curr){
        int  cnt =0;
                while(curr){
                      if(curr%2)cnt++;
                      curr /=2;
                }
            return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
            for(int i=0;i<arr.size();i++)
        {
            arr[i]+=bitCount(arr[i])*10001;
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]%10001;
        }
        return arr;
    }
};