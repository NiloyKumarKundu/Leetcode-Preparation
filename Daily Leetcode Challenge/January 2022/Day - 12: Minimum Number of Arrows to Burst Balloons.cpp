bool comp(vector<int>& x, vector<int>& y) { 
    return x[1] < y[1]; 
} 

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        if (points.size() == 1) {
            return 1;
        }
        int arrows = 1;
        
        sort(points.begin(), points.end(), comp);
        
        int current = points[0][1];
        
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= current) {
                continue;
            } else {
                current = points[i][1];
                arrows++;
            }
        }
        
        return arrows;
    }
};