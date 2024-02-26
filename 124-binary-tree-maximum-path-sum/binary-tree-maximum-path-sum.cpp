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
    int maxSum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int left = max(maxSum(root->left, maxi), 0);
        int right = max(maxSum(root->right, maxi), 0);
        maxi = max(maxi, left+right+root->val);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int maximum = INT_MIN;
        maxSum(root, maximum);
        return maximum;
    }
};