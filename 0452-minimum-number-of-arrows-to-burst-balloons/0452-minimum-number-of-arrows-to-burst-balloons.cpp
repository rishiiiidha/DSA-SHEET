class Solution {
public:
    static bool comporator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comporator);
        int n = points.size();
        int k = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (points[i][0] > points[k][1]) {
                cnt++;
                k = i;
            }
        }
        return cnt;
    }
};