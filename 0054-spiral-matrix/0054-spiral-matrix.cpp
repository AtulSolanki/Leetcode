class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int  m = matrix.size(), n = matrix[0].size();
        vector<int>ans;
        int top=0,left=0,right=n-1,bottom=m-1,dir=0;
        while((top<=bottom && left<=right)){
            dir=dir%4;
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
              else{
                for(int i=bottom ;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
        }
        return ans;
    }
};