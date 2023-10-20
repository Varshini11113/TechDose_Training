// Question

// You are given an undirected graph of N nodes and
// M edges. Your task is to create the graph and print
// the adjacency list of the graph. It is guaranteed that
// all the edges are unique, i.e., if there is an edge from
// 'X' to 'Y', then there is no edge present from 'Y' to 'X'
// and vice versa. Also, there are no self-loops present
// in the graph.

// Solution
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int>adj[n];
    for(int i = 0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector < vector < int >> ans(n);
    for(int i = 0; i<n; i++){
        ans[i].push_back(i);
        for(int j = 0; j<adj[i].size(); j++){
            ans[i].push_back(adj[i][j]);
        }
    }
    return ans;
}


//Question
/*
    Given 'n'  vertices return the no of graphs possible
    no self loop and multiple edges
    components allowed
*/

//Solution
int countingGraphs(int N)
{
    // Write your code here.
    return pow(2,(N*(N-1))/2);
}