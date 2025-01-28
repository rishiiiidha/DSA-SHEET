class Solution {
public:
    bool canJump(vector<int>& nums) {
        // minimum jumps 
        int n = nums.size();
        int maxi = nums[0];
        maxi--;
        for(int i=1;i<n;i++){
            if(maxi < 0) return false;
            maxi = max(maxi , nums[i]);
            maxi--;
            
        }
        return true;
        
    }
};