/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        int maxi = max(p->val, q->val);
        int mini = min(p->val, q->val);
        while(root != NULL){
            if(maxi < root->val){
                root = root->left;
            }
            else if(mini > root->val){
                root = root->right;
            }
            else
            return root;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        return find(root,p,q);
    }
};