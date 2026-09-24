class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);

        // Left subtree is already unbalanced
        if (leftHeight == -1)
            return -1;

        int rightHeight = height(root->right);

        // Right subtree is already unbalanced
        if (rightHeight == -1)
            return -1;

        // Current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};