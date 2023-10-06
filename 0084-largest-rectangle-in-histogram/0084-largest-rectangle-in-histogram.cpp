class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int n =heights.size();
        int left[n],right[n];
        for(int i=0;i<n;i++){
             
             while(!st.empty()){
                 int idx = st.top().first;
                 int val = st.top().second;
                 if(val<heights[i]){
                     left[i]=idx;
                     break;
                 }
                 else st.pop();
             }
             if(st.empty()){
                 left[i]=-1;
             }
             st.push({i,heights[i]});
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            
             while(!st.empty()){
                 int idx = st.top().first;
                 int val = st.top().second;
                 if(val<heights[i]){
                     right[i]=idx;
                     break;
                 }
                 else st.pop();
             }
              if(st.empty()){
                 right[i]=n;
             }
             st.push({i,heights[i]});
        }
        for(int i=0;i<n;i++){
            cout << left[i] << " ";
        }
        cout << endl;
         for(int i=0;i<n;i++){
            cout << right[i] << " ";
        }
        cout << endl;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,(right[i]-left[i]-1)*heights[i]);
        }
        return maxi;
    }
};