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
    int amountTime(TreeNode* target, map<TreeNode*, TreeNode*>parent){
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*, int>vis;
        vis[target] = 1;
        int count = 0;
        while(!q.empty()){
             int flag = 0;
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag = 1;
                    q.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis[node->right]){
                    flag = 1;
                    q.push(node->right);
                    vis[node->right] = 1;
                }
                if(parent[node] && !vis[parent[node]]){
                    flag = 1;
                    q.push(parent[node]);
                    vis[parent[node]] = 1;
                }
            }
            if(flag) count++;
        }
        return count;
    }
    TreeNode* findParent(TreeNode* root, map<TreeNode*, TreeNode*>&parent, int start){
        queue<TreeNode*>q;
        TreeNode* res = NULL;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start) res = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
    //    if(root == NULL) return 0;
       //to find the parent elements
        map<TreeNode*, TreeNode*>parent;
        TreeNode* target = findParent(root, parent, start);
        int time = amountTime(target, parent);
        return time;
    }
};