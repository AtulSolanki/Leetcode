class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
          vector<vector<int>>v(32);
          int n = arr.size();
          for(int i=0;i<n;i++){
               int curr = arr[i] , cnt =0;
                while(curr){
                      if(curr%2)cnt++;
                      curr /=2;
                }
                v[cnt].push_back(arr[i]);
          }
          int ind = 0 ;
         for(int i=0;i<32;i++){
             sort(v[i].begin(),v[i].end());
             for(int j=0;j<v[i].size();j++){
                 arr[ind++] = v[i][j];
             }
          }
          return arr;
    }
};