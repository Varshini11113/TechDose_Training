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
    int find(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int left = max(find(root->left, maxi), 0);
        int right = max(find(root->right, maxi), 0);
        maxi = max(maxi, root->val+left+right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return NULL;
        int maxi = INT_MIN;
        find(root, maxi);
        return maxi;
    }
};