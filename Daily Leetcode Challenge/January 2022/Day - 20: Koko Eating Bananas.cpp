// Time Complexity: O(NlogN)
// Space Complexity: O(1)
class Solution {
    bool isPossible(vector<int>& piles, int mid, int h) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil(piles[i] / (mid * 1.0));   
        }
        return time <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (auto i : piles) {
            maxi = max(i, maxi);
        }
        
        if (piles.size() == h) {
            return maxi;
        }
        
        int lo = 1, hi = maxi, speed = INT_MAX;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(piles, mid, h)) {
                speed = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return speed;
    }
};