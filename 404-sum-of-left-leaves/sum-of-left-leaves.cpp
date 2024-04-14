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
    int sum = 0;
    void find(TreeNode *root, bool left){
        if(!root) return;
        if(left && !root->left && !root->right){
            sum += root->val;
        }
        find(root->left, true);
        find(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        find(root, false);
        return sum;
    }
};