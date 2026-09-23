class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            // Visit root
            ans.push_back(node->val);

            // Push right first
            if (node->right)
                st.push(node->right);

            // Push left second
            if (node->left)
                st.push(node->left);
        }

        return ans;
    }
};