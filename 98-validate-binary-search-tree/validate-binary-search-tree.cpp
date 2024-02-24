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
    void inorder(TreeNode* root, vector<int>&ans){
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return false;
        vector<int>ans;
        inorder(root, ans);
        int n = ans.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(ans[i] >= ans[j]){
                    return false;
                }
            }
            cout << ans[i] << " ";
        }
        return true;
    }
};