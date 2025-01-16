/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        while (!q.empty()) {
            vector<int> temp;
            int k = q.size();
            for (int i = 0; i < k; i++) {
                TreeNode* r = q.front();
                q.pop();
                temp.push_back(r->val);
                if (r->left != nullptr)
                    q.push(r->left);
                if (r->right != nullptr)
                    q.push(r->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};