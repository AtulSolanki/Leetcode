class Solution {
public:
bool same(int a,int b){
    if((a>0 && b>0) || (a<0 && b<0) || (a<0 && b>0))return true;
    return false;
}
    vector<int> asteroidCollision(vector<int>& A) {
         vector<int> ans;
         stack<int>st;
         int n = A.size();
         for(int i=0;i<n;i++){
              if(st.empty() || same(st.top(),A[i])){
                  st.push(A[i]);
              }
              else{
                  while(!st.empty() && st.top()>0 &&st.top()<abs(A[i])){
                      st.pop();
                  }
                  if(st.empty() || (st.top()<0 && A[i]<0)){
                      st.push(A[i]);
                  }
                  if(st.top()==abs(A[i])){
                      st.pop();
                  }
              }
         }
         while(!st.empty()){
             ans.push_back(st.top());
             st.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};