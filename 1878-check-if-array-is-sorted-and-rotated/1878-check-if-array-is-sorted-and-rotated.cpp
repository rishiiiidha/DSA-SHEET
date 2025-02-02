class Solution {
public:
    bool check2(vector<int>& nums, int idx) {
        reverse(nums.begin(), nums.begin() + idx);
        reverse(nums.begin() + idx, nums.end());
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                if (check2(nums, i))
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};