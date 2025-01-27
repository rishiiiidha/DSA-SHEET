class Solution {
public:
    vector<int> monotonicstack(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> nextgreater(n, -1);
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                while (!st.empty() && arr[st.top()] < arr[i]) {
                    nextgreater[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        for (int i = 0; i < n; i++)
            cout << nextgreater[i] << " ";
        return nextgreater;
    }
    vector<int> nextGreaterElements(vector<int>& n1) {
        vector<int> nextgreater = monotonicstack(n1);
        vector<int> ans;
        int m = n1.size();
        for (int i = 0; i < m; i++) {
            if (nextgreater[i] == -1) {
                ans.push_back(-1);
            } else
                ans.push_back(n1[nextgreater[i]]);
        }
        return ans;
    }
};