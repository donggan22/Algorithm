
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target->val);
        return ans;
    }
    void dfs(TreeNode* node, int val)
    {
        if (ans != nullptr)
            return;
        if (node->val == val)
        {
            ans = node;
            return;
        }
        if (node->left != nullptr)
            dfs(node->left, val);
        if (node->right != nullptr)
            dfs(node->right, val);
        return;
    }
}//using dfs;