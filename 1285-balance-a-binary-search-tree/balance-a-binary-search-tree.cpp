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
    vector<int>arr;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedArray(0, arr.size()-1);
    }
    TreeNode* sortedArray(int start, int end){
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* begin = new TreeNode(arr[mid]);
        begin->left = sortedArray(start, mid-1);
        begin->right = sortedArray(mid+1, end);
        return begin;
    }
};