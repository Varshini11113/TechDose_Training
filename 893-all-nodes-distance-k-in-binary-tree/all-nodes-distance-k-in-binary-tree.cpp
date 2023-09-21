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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<int, TreeNode*>parent;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                auto top = q.front();
                q.pop();
                if(top->left){
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if(top->right){
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }

        unordered_map<int, int>visited;
        q.push(target);
        while(k-- && !q.empty()){
            int n = q.size();
            for(int i = 0; i<n; i++){
                auto top = q.front();
                q.pop();

                visited[top->val] = 1;

                if(top->left && !visited[top->left->val]){
                    q.push(top->left);
                }
                if(top->right && !visited[top->right->val]){
                    q.push(top->right);
                }
                if(parent[top->val] && !visited[parent[top->val]->val]){
                    q.push(parent[top->val]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};