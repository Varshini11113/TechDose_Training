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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int l = height(root->left);
        int h = height(root->right);
        if(l == 0 || h == 0) return l+h+1;
        return 1 + min(l, h);
    }
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // int dia = 0;
        return height(root);
        
    }
};