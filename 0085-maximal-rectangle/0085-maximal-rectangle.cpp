class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxi = 0;
         for(int i=0;i<=n;i++){
             while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                 int h = heights[st.top()];
                 st.pop();
                 int width;
                 if(st.empty())width = i;
                 else width = i-st.top()-1;
                 maxi  = max(maxi, h*width);
             }
             st.push(i);
         }
         return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
          int n = matrix.size(), m = matrix[0].size(),maxi=0;
           vector<int>v(m,0);
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   if(matrix[i][j]=='1')v[j]++;
                   else v[j]= 0;
               }
               maxi = max(maxi,largestRectangleArea(v));

           }
           return maxi;
    }
};