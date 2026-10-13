class Solution {
public:
    int dfs(TreeNode* root, int currentNum) {
        if (root == nullptr)
            return 0;

        // Build the number
        currentNum = currentNum * 10 + root->val;

        // If leaf node, return the number
        if (root->left == nullptr && root->right == nullptr) {
            return currentNum;
        }

        // Calculate sum from both subtrees
        return dfs(root->left, currentNum) +
               dfs(root->right, currentNum);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};