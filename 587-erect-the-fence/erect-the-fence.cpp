class Solution {
public:
    bool isClockWise(vector<int>&a, vector<int>&b, vector<int>&c){
        int x1 = a[0], x2 = b[0], x3 = c[0];
        int y1 = a[1], y2 = b[1], y3 = c[1];
        return ((y3 - y2) * (x2 - x1)) - ((y2 - y1) * (x3 - x2)) >= 0;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>>hull;
        int n = trees.size();
        auto comparator = [&](vector<int>&a, vector<int>&b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };
        sort(trees.begin(), trees.end(), comparator);

        for(int i = 0; i<n; i++){
            while(hull.size() > 1 && !isClockWise(hull[hull.size()-2], hull[hull.size()-1], trees[i])){
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        for(int i = n-2; i>=0; i--){
            while(hull.size() > 1 && !isClockWise(hull[hull.size()-2], hull[hull.size()-1], trees[i])){
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }

        set<vector<int>> uniquePts(hull.begin(), hull.end());
        hull.assign(uniquePts.begin(), uniquePts.end());
        return hull;
    }
};