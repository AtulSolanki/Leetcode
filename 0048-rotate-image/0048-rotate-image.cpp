class Solution {
private:
    void swap(vector<vector<int>>& m,int i,int j){
        int temp=m[i][j];
        m[i][j]=m[j][i];
        m[j][i]=temp;
    }
    void reverse(vector<vector<int>>& m,int n,int i){
        int l=0,r=n-1;
        while(l<r){
            int temp=m[i][l];
            m[i][l]=m[i][r];
            m[i][r]=temp;
            l++;r--;
        }
    }
  
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                swap(m,i,j);
            }
        }
        for(int i=0;i<n;i++){
            reverse(m,n,i);
        }
        
    }
};