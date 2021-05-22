
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#define INF -2147483649
double prev = INF;

void inorder(TreeNode* root ,bool &flag)
{
    if(!root || !flag)
        return;

    inorder(root->left,flag);
    if(root->val <= prev) {
        flag = false;
        return;
    }
    else
        prev = root->val;
    inorder(root->right,flag);
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool flag =true;
        prev = INF;
        inorder(root,flag);
        return flag;
    }
};