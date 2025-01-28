class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int start = 0;
        int end = n;
        vector<int> temp;
        sort(intervals.begin(), intervals.end());
        while (start < end) {
            int mini = intervals[start][0];
            int maxi = intervals[start][1];
            while (start != n - 1 &&
                   maxi >= intervals[start + 1][0]) {
                mini = min(mini, intervals[start + 1][0]);
                maxi = max(maxi, intervals[start + 1][1]);
                start++;
            }
            temp.push_back(mini);
            temp.push_back(maxi);
            ans.push_back(temp);
            temp.clear();
            
            start++;
        }
        return ans;
    }
};