class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            // Push left first
            if (node->left)
                st.push(node->left);

            // Push right second
            if (node->right)
                st.push(node->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};