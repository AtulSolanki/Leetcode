class Solution {
public:
    
    bool dfs(int node,vector<bool>&vis,vector<bool>&pathVis,vector<vector<int>>& adj){
       
       vis[node] = 1;
       pathVis[node]=1;
       for(auto it: adj[node]){
           if(!vis[it]){
               if(dfs(it,vis,pathVis,adj))return true;
           } 
           else if(pathVis[it]) {
               return true;
           }
       }
       pathVis[node]=0;
       return false;
   }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n,0), pathVis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
               dfs(i,vis,pathVis,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!pathVis[i])ans.push_back(i);
        }
        return ans;
    }
};