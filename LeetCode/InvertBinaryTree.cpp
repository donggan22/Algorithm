class Solution {
public:
    void myorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        if (root->left != nullptr)
            myorder(root->left);
        if (root->right != nullptr)
            myorder(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        myorder(root);
        return root;
    }
};
//Use postorder