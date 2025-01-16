class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans1 = 0;
        for (int i = 0; i < m; i++) {
            ans1 = ans1 ^ nums2[i];
        }
        int ans2 = 0;
        for (int i = 0; i < n; i++) {
            ans2 = ans2 ^ nums1[i];
        }
        if (n % 2 == 0 && m % 2 == 0)
            return 0;
        else if (n % 2 != 0 && m % 2 == 0) {
            return ans1;
        } else if (n % 2 == 0 && m % 2 != 0) {

            return ans2;
        } else {
            return ans1 ^ ans2;
        }

        return -1;
    }
};
