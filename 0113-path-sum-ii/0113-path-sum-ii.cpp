class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return;

        // Add current node to path
        path.push_back(root->val);

        // Check if it is a leaf
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                ans.push_back(path);
            }
        }
        else {
            // Search left and right subtrees
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};