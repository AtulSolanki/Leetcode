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
};