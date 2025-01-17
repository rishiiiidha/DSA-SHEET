class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int final = 0;
        for(auto i:derived){
            final = final ^ i;
        }
        if(final) return false;
        return true;
    }
};