class Solution {
public:
    unordered_map<int, int> indexMap;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        // Last unused postorder element is the root
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = indexMap[rootValue];

        // Build right subtree first
        root->right = build(postorder, mid + 1, right);

        // Then build left subtree
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Store inorder positions
        for (int i = 0; i < n; i++) {
            indexMap[inorder[i]] = i;
        }

        postIndex = n - 1;

        return build(postorder, 0, n - 1);
    }
};