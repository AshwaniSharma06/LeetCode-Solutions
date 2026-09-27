class Solution {
public:
    unordered_map<int, int> indexMap;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;

        // Current preorder element is the root
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = indexMap[rootValue];

        // Build left subtree first
        root->left = build(preorder, left, mid - 1);

        // Then build right subtree
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder positions
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        return build(preorder, 0, inorder.size() - 1);
    }
};