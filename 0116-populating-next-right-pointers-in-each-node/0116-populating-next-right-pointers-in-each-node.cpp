class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* level = root;

        // Stop when we reach the leaf level
        while (level->left != nullptr) {
            Node* curr = level;

            while (curr != nullptr) {
                // Connect children of the same parent
                curr->left->next = curr->right;

                // Connect children of neighboring parents
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            // Move to the next level
            level = level->left;
        }

        return root;
    }
};