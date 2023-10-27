class Solution {
public:
    string minRemoveToMakeValid(string s) {
         int stack_size =0 ,n  = s.size();
         stack<int>st,st2;
         for(int i=0;i<n;i++){
             if(s[i]=='('){st.push(i);stack_size++;}
             else if(s[i]==')' && stack_size>0){st.pop();stack_size--;}
             else if(s[i]==')' ){
                 st2.push(i);
             }
              
         }
         set<int>S;
         string t = "";
         while(!st.empty()){
             S.insert(st.top());
             st.pop();
         }
         while(!st2.empty()){
             S.insert(st2.top());
             st2.pop();
         }
         for(int i=0;i<n;i++){
             if(S.find(i)==S.end()){
                 t+= s[i];
             }
         }
         return t;
    }
};