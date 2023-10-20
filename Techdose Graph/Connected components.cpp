//Question

// You are given 'n'cities, some of which are connected
// by bidirectional roads. You are also given an 'n x n'
// matrix i.e. 'roads', where if city 'i' and 'j' are
// connected by a road then roads[i][j]= 1, otherwise roads[i] = O.
// A province is a group of cities that are either directly
// or indirectly connected to each other through roads.
// The goal is to count and return the total number of
// such provinces in the given matrix.

//solution
void dfs(int node, vector<int>&vis, vector<int>adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, adj);
        }
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int>adj[n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(roads[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>vis(n,0);
    int count = 0;
    for(int i = 0; i<n; i++){
        if(!vis[i]){
            count++;
            dfs(i, vis, adj);
        }
    }
    return count;
}