/*
Question

Given a DAG(direct acyclic graph), print Topological
Sorting of a given graph

*/

//Solution
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int n) {
    // Write your code here!
    vector<int>adj[n];
    int ind[n] = {0};
    for(auto it : graph){
        adj[it[0]].push_back(it[1]);
        ind[it[1]]++;
    }
    queue<int>q;
    for(int i = 0; i<n; i++){
        if(ind[i] == 0) q.push(i);
    }
    vector<int>ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            ind[it]--;
            if(ind[it] == 0) q.push(it);
        }
    }
    return ans;
}
