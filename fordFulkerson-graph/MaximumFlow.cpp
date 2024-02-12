#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& graph, int s, int t, vector<int>& parent) {
    int n = graph.size();
    vector<int>visited(n, 0);
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(!visited[v] && graph[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int n = graph.size();
    vector<int>parent(n, -1);
    int maxFlow = 0;
    while(bfs(graph, s, t, parent)) {
        int currFlow = INT_MAX;
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            currFlow = min(currFlow, graph[u][v]);
        }
        for(int v = t; v != s; v = parent[v]){
            int u = parent[v];
            graph[u][v] -= currFlow;
            graph[v][u] += currFlow;
        }
        maxFlow += currFlow;
    }
    return maxFlow;
}

int main() {
    int V = 6;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    graph[0][1] = 16;
    graph[0][2] = 13;
    graph[1][2] = 10;
    graph[1][3] = 12;
    graph[2][1] = 4;
    graph[2][4] = 14;
    graph[3][2] = 9;
    graph[3][5] = 20;
    graph[4][3] = 7;
    graph[4][5] = 4;
    int source, sink;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the sink vertex: ";
    cin >> sink;
    cout << "The maximum possible flow is " << fordFulkerson(graph, source, sink);
    return 0;
}
