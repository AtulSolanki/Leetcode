//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
       vector<vector<int>>adj(k);
    vector<int>vis(k,0),indegree(k,0);
    for(int i=0;i<n-1;i++){
         int j = 0;
        while(j<dict[i].size() && j<dict[i+1].size()){
            if(dict[i][j] != dict[i+1][j]){
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                indegree[dict[i+1][j]-'a']++;
                break;
            }
            j++;
        }
    }
    //stack<int>st;
    queue<int>q;
     string s ="";
    for(int i=0;i<k;i++){
        if(indegree[i]==0){
           s.push_back('a'+i);
           q.push(i);
        }
    }
   
    while (!q.empty()) {
       auto node= q.front();
       q.pop();
      for(auto it:adj[node]){
           if(--indegree[it]==0){
             s.push_back('a'+it);
             q.push(it);
           }
      }
    }
    //cout << s << endl;
    return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends