class Solution {
public:
    static bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<pair<int, int>> v;
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            int sz = graph[i].size();
            v.push_back({i, sz});
        }
        sort(v.begin(), v.end(), compare);
        // for(auto i:v){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        unordered_map<int, int> safenodes;
        int x=0;
        for (int i = 0; i < n; i++) {
            for (auto pr : v) {
                int idx = pr.first;
                int sz = pr.second;
                if (sz == 0)
                    safenodes[idx]++;
                else {
                    bool notfind = false;
                    for (int i = 0; i < sz; i++) {
                        if (safenodes.find(graph[idx][i]) == safenodes.end()) {
                            notfind = true;
                        }
                    }
                    if (!notfind) {
                        safenodes[idx]++;
                    }
                }
            }
            if(x==(int)safenodes.size()) break;
            x=safenodes.size();
        }
        vector<int> ans;
        for (auto i : safenodes) {
            ans.push_back(i.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};