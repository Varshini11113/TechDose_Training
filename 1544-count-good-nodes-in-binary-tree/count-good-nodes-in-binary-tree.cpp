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
    int count = 0;
    int maxNode(TreeNode* root, int curr_max){
        if(root == NULL) return 0;
        if(root->val >= curr_max){
            count++;
            curr_max = root->val;
        }
        maxNode(root->left, curr_max);
        maxNode(root->right, curr_max);
        return count;
    }
    int goodNodes(TreeNode* root) {
        maxNode(root, root->val);
        return count;
    }
};