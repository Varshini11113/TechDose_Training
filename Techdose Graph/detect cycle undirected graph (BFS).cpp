// Question
// Problem Statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
// Example 1:
// Input:
// V = 8, E = 7
// Output:  0
// Explanation: No cycle in the given graph.

// Example 2:
// Input:
// V = 8, E = 6
// Output: 1 
// Explanation: 4->5->6->4 is a cycle.
class Graph {
private:
    bool isCycle(int node, vector<int>&vis, vector<int>adj[]){
        vis[node] = 1;
        queue<pair<int, int>>q;
        q.push({node, -1});
        while(!q.empty()){
            int nn = q.front().first;
            int pp = q.front().second;
            q.pop();
            for(auto it : adj[nn]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, nn});
                }
                else{
                    if(it != pp){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int>vis(V,0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                int ans = isCycle(i, vis, adj);
                if(ans == 1){
                    return true;
                }
            }
        }
        return false;
    }
};