class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int k = flowerbed.size();
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int count = 0;
        
        for (int i = 1; i <= k; i++) {
            if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                count++;
            }
        }
        
        return count >= n;
    }
};