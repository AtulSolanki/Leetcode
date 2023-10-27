class Solution {
public:
    string minRemoveToMakeValid(string s) {
         int n  = s.size();
         stack<int>st;
         for(int i=0;i<n;i++){
             if(s[i]=='('){st.push(i);}
             else if(s[i]==')' && st.size()>0){st.pop();}
             else if(s[i]==')' ){
                 s[i] = '*';
             }
              
         }
         string t = "";
         while(!st.empty()){
             s[st.top()] = '*';
             st.pop();
         }
         for(int i=0;i<n;i++){
             if(s[i]!='*'){
                 t+= s[i];
             }
         }
         return t;
    }
};