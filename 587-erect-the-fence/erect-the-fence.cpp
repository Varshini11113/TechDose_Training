class Solution {
public:
    // Check if moving from point a to point b to point c results in a clockwise turn
    bool isClockwiseTurn(vector<int> &a, vector<int> &b, vector<int> &c) {
        int x1 = a[0], x2 = b[0], x3 = c[0];
        int y1 = a[1], y2 = b[1], y3 = c[1];
        return ((y3 - y2) * (x2 - x1)) - ((y2 - y1) * (x3 - x2)) >= 0;
    }
    
    // Find the convex hull of a set of points
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int>> hull;
        int n = points.size();
       
        // Comparator to sort points based on their x-coordinate and then y-coordinate
        auto comparator = [&](vector<int> &a, vector<int> &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] < b[1];
        };
        
        sort(points.begin(), points.end(), comparator);
        
        // Build the upper part of the convex hull
        for(int i = 0; i < n; i++) {
            while(hull.size() > 1 && !isClockwiseTurn(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        // Build the lower part of the convex hull
        for(int i = n - 2; i >= 0; i--) {
            while(hull.size() > 1 && !isClockwiseTurn(hull[hull.size() - 2], hull[hull.size() - 1], points[i])) {
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }
        
        set<vector<int>> uniquePoints(hull.begin(), hull.end());
        hull.assign(uniquePoints.begin(), uniquePoints.end());
        return hull;
    }
};
