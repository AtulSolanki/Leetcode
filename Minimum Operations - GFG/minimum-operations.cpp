//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int solve(int n){
        if(n==1)return 1;
        if(n%2)return 1+ solve(n-1);
        return 1 + solve(n/2);
    }
    int minOperation(int n)
    {
       return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends