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
    int generate(TreeNode* root, int maxi){
        if(root == NULL) return 0;
        if(root->val >= maxi){
            count++;
            maxi = root->val;
        }
        generate(root->left, maxi);
        generate(root->right, maxi);
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = generate(root, root->val);
        return count;
    }
};