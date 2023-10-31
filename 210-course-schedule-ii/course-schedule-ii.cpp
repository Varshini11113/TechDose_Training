class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int>ind(n,0);
        for(int i = 0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i = 0; i<n; i++){
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                if(--ind[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == n) return ans;
        else return vector<int>();
    }
};