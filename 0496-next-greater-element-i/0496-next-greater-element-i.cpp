class Solution {
public:
    vector<int> monotonicstack(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nextgreater(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                nextgreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return nextgreater;
    }
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        unordered_map<int, int> mp;
        int n = n2.size();
        for (int i = 0; i < n; i++) {
            mp[n2[i]] = i;
        }
        vector<int> nextgreater = monotonicstack(n2);
        for (int i = 0; i < n; i++)
            cout << nextgreater[i] << " ";
        vector<int> ans;
        int m = n1.size();
        for (int i = 0; i < m; i++) {
            if (nextgreater[mp[n1[i]]] == -1) {
                ans.push_back(-1);
            } else
                ans.push_back(n2[nextgreater[mp[n1[i]]]]);
        }
        return ans;
    }
};