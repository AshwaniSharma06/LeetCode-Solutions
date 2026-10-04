class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->left != nullptr) {

                // Find the rightmost node of the left subtree
                TreeNode* prev = curr->left;

                while (prev->right != nullptr) {
                    prev = prev->right;
                }

                // Attach original right subtree
                prev->right = curr->right;

                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move to the next node
            curr = curr->right;
        }
    }
};