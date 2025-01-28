class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1 = g.size();
        int n2 = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i<n1 && j<n2){
            if(g[i]<=s[j]) {
                i++;
                j++;
                cnt++;
            }else {
                j++;
            }
        }
        return cnt;
    }
};