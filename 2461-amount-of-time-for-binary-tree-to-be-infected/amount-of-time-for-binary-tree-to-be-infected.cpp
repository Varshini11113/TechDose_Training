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
    int minTime(TreeNode* root,map<TreeNode*, TreeNode*>mp){
        queue<TreeNode*>q;
        map<TreeNode*, int>vis;
        int count = 0;
        vis[root] = 1;
        q.push(root);
        while(!q.empty()){
            int flag = 0;
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL && !vis[node->left]){
                    flag = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right != NULL && !vis[node->right]){
                    flag = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }
                if(mp[node] && !vis[mp[node]]){
                    flag = 1;
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                }
            }
            if(flag) count++;
        }
        return count;
    }
    TreeNode* findTarget(TreeNode* root,map<TreeNode*, TreeNode*>&mp, int start){
        queue<TreeNode*>q;
        TreeNode* res;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start){
                res = node;
            } 
            if(node->left != NULL){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right != NULL){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL) return 0;
        map<TreeNode*, TreeNode*>parent;
        TreeNode* target = findTarget(root, parent, start);
        int count = minTime(target, parent);
        return count;
    }
};