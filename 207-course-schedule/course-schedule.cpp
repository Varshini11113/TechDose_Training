class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& gn) {
        // vector<int>adj[n];
        // int m = gn.size();
        // vector<int>ind(n,0);
        // // for(int i = 0; i<m; i++){
        // //     adj[gn[i].first].push_back(gn[i].second);
        // //     ind[gn[i].second]++;
        // // }
        // // for(auto ele : gn){
        // //     adj[ele[0]].push_back(ele[1]);
        // //     ind[ele[1]]++;
        // // }
        // for(int i = 0; i<m; i++){
        //     adj[gn[i][0]].push_back(gn[i][1]);
        //     ind[gn[i][1]]++;
        // }
        // queue<int>q;
        // for(int i = 0; i<n; i++){
        //     if(ind[i] == 0) q.push(i);
        // }
        // while(!q.empty()){
        //     n--;
        //     int node = q.front();
        //     q.pop();
        //     for(auto it : adj[node]){
        //         if(--ind[it] == 0) q.push(it);
        //     }
        // }
        // return n == 0;
        vector<int>adj[n];
        int m = gn.size();
        for(int i = 0; i<m; i++){
            adj[gn[i][0]].push_back(gn[i][1]);
        }
        vector<int>ind(n,0);
        for(int i = 0; i<n; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(ind[i] == 0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node]){
                if(--ind[it] == 0) q.push(it);
            }
        }
        return ans.size() == n;
    }
};