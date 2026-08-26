class Solution {
public:
    vector<TreeNode*> build(int start, int end) {

        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> trees;

        for (int rootVal = start; rootVal <= end; rootVal++) {

            vector<TreeNode*> leftTrees =
                build(start, rootVal - 1);

            vector<TreeNode*> rightTrees =
                build(rootVal + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* root = new TreeNode(rootVal);

                    root->left = left;
                    root->right = right;

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};