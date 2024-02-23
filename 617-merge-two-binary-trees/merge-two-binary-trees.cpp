/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sum(TreeNode* s, TreeNode* t){
        if(s && t) {
            TreeNode* node = new TreeNode(s->val + t->val);
            node->left = sum(s->left, t->left);
            node->right = sum(s->right, t->right);
            return node;
        }
        return s ? s : t;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        return sum(root1, root2);
    }
};