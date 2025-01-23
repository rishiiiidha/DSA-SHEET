class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows;
        vector<int> cols;

        for (int i = 0; i < n; i++) {
            int sum1 = 0;
            for (int j = 0; j < m; j++) {
                sum1 += grid[i][j];
            }
            rows.push_back(sum1);
        }
        for (int i = 0; i < m; i++) {
            int sum2 = 0;
            for (int j = 0; j < n; j++) {
                sum2 += grid[j][i];
            }
            cols.push_back(sum2);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
                    res += 1;
                }
            }
        }
        return res;
    }
};