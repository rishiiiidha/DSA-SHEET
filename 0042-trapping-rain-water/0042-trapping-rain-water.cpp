class Solution {
public:
    // finding prev greater and next greater in same monotonic stack
    void monotonicstack(vector<int>& prevg, vector<int>& nextg,
                        vector<int>& height) {
        stack<int> st;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                // nextg => greater than or equal to
                nextg[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && height[st2.top()] <= height[i]) {
                // prevg => strictly greater than
                st2.pop();
            }
            if (!st2.empty()) {
                prevg[i] = st2.top();
            }
            st2.push(i);
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> prevg(n, -1);
        vector<int> nextg(n, -1);
        monotonicstack(prevg, nextg, height);
        for (int i = 0; i < n; i++)
            cout << prevg[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << nextg[i] << " ";
        cout<<endl;
        for (int i = 0; i < n; i++) {
            int pr = prevg[i];
            int ne = nextg[i];
            int ans = 0;
            if (pr != -1 && ne != -1) {
                cout << pr << endl;
                cout << ne << endl;
                ans = 0;
                int mini = min(height[pr], height[ne]);
                for (int j = pr + 1; j < ne; j++) {
                    ans += mini - height[j];
                    height[j]=mini;
                }
                res += ans;
            }
        }
        return res;
    }
};
