class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->left == nullptr) {

                // Detect swapped nodes
                if (prev != nullptr && prev->val > curr->val) {
                    if (first == nullptr)
                        first = prev;

                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                // Find inorder predecessor
                while (pred->right != nullptr &&
                       pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Create temporary link
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // Remove temporary link
                    pred->right = nullptr;

                    // Detect swapped nodes
                    if (prev != nullptr && prev->val > curr->val) {
                        if (first == nullptr)
                            first = prev;

                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Recover BST by swapping values
        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};