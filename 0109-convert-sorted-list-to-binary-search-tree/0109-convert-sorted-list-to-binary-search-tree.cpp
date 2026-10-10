class Solution {
public:
    TreeNode* build(ListNode*& head, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        // Build left subtree
        TreeNode* leftTree = build(head, left, mid - 1);

        // Current list node becomes root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftTree;

        // Move to next list node
        head = head->next;

        // Build right subtree
        root->right = build(head, mid + 1, right);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        // Count nodes
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        return build(head, 0, n - 1);
    }
};