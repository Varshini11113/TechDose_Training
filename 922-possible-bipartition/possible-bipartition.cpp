class Solution {
private:
    bool dfs(int node, int col, vector<int>&color, vector<int>adj[]){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(dfs(it, !col, color, adj) == false) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();
        vector<int>adj[n+1];
        vector<int>color(n+1,-1);
        for(auto &it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 1; i<=n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, adj) == false) return false;
            }
        }
        return true;
    }
};