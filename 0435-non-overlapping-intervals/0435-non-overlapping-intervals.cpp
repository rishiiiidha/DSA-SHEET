class Solution {
public:
    static bool comporator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comporator);
        int n = intervals.size();
        int k = 0;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[k][1]) {
                cnt++;
                k=i;
            }
        }
        return n-cnt-1;
    }
};