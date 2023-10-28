class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        int x = b.size()/a.size();
        string na = "";
        int cnt =0;
        while(cnt!=x){
            na += a;
            cnt++;
        }
        if(na==b)return x;
        na += a;
        if(na.find(b) != string::npos){
            return x+1;
        }
        na += a;
        if(na.find(b) != string::npos){
            return x+2;
        }
        return -1;
    }
};