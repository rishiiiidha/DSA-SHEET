class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>idx;
        int n = boxes.size();
        for(int i=0;i<n;i++){
            if(boxes[i]=='1') idx.push_back(i);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int rrr=0;
            for(auto k : idx){
                rrr+=abs(k-i);
            }
            ans.push_back(rrr);
        }
        return ans;
        
    }
};