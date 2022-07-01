class Solution {
public:
    
    bool static compare (vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int totalUnit = 0, w = 0;
        
        for (auto i : boxTypes) {
            if (i[0] <= truckSize) {
                totalUnit += (i[0] * i[1]);
                truckSize -= i[0];
            } else {
                int x = truckSize;
                totalUnit += x * i[1];
                break;
            }
        }
        
        return totalUnit;
    }
};