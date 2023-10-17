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
    int dfs(TreeNode* node, int curr_max){
        if(node == NULL) return 0;
        if(node->val >= curr_max){
            count++;
            curr_max = node->val;
        }
        dfs(node->left, curr_max);
        dfs(node->right, curr_max);
        return count;
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};