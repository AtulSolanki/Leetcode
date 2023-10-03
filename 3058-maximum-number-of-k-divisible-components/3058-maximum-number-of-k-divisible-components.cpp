class Solution {
public:
    int ans = 0 ;
    int dfs(int node, int par, vector<int>& values, int k, vector<vector<int>>& adj){
         int val = values[node];
         for(auto it: adj[node]){
             if(par!=it)  val += dfs(it,node,values,k,adj);
         }
        if(val%k==0){
           ans++;
           val = 0;  
        }
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,values,k,adj);
        return ans;
    }
};