class Solution {
public:
    int minPartitions(string n) {
        int sz = n.size();
        int maxi = INT_MIN;
        for(int i=0;i<sz;i++){
             maxi=max(maxi,(int)n[i]-'0');
        } 
        return maxi;
    }
};
