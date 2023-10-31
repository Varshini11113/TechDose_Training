class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>ind(n,0);
        for(int i = 0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            ind[pre[i][1]]++;
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            n--;
            for(auto it : adj[node]){
                if(--ind[it] == 0) q.push(it);
            }
        }
        return n == 0;
    }
};