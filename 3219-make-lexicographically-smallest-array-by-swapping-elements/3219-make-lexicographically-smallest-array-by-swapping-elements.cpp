class Solution {
public:
    // static bool compare(const pair<int,int>&p1 , const pair<int,int>&p2){
    //     return p1.first < p2.first;
    // }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        vector<vector<pair<int, int>>> letsmakegroup;
        letsmakegroup.push_back({v[0]});
        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i - 1].first <= limit) {
                letsmakegroup.back().push_back(v[i]);
            } else {
                letsmakegroup.push_back({v[i]});
            }
        }

        for (auto tr : letsmakegroup) {
            int k = tr.size();
            vector<int> indices;
            for (auto i : tr) {
                cout << i.first << " ";
                indices.push_back(i.second);
            }
            sort(indices.begin(), indices.end());
            for (int i = 0; i < k; i++) {
                nums[indices[i]] = tr[i].first;
            }
            cout << endl;
        }

        return nums;
    }
};
