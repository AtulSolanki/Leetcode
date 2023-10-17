class Solution {
public:
    vector<int> temp;
    Solution(vector<int>& w) {  
        temp.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            temp.push_back(w[i]+temp.back());
        }
        
    }
    
    int pickIndex() {
        int x = temp.back();
        int val = rand() % x;
        int ind = upper_bound(temp.begin(),temp.end(),val) - temp.begin();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */