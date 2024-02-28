/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*>q;
        q.push(root);
        string str = "";
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) str.append("#,");
            else{
                str.append(to_string(node->val) + ",");
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            TreeNode* newNode = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#"){
                newNode->left = NULL;
            }
            else{
                TreeNode* left = new TreeNode(stoi(str));
                newNode->left = left;
                q.push(left);
            }
            getline(s, str, ',');
            if(str == "#"){
                newNode->right = NULL;
            }
            else{
                TreeNode* right = new TreeNode(stoi(str));
                newNode->right = right;
                q.push(right);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));