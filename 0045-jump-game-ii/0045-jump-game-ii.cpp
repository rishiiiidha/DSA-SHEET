class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        int jumps = 0;
        int range = 0;
        int farthest = 0;
        if(n==1) return 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == range) {
                jumps++;
                range = farthest;
                if (range >= n - 1)
                    break;
            }
        }
        return jumps;
    }
};