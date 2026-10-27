
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        Node* curr = root;

        while (curr != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;

            // Traverse the current level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;
            }

            // Move to the next level
            curr = dummy.next;
        }

        return root;
    }
};
