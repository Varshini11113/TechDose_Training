class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrow = points[0][1];
        int ans = 1;
        for(auto p : points){
            if(p[0] > arrow){
                ans++;
                arrow = p[1];
            }
            arrow = min(p[1], arrow);
        }
        return ans;
    }
};