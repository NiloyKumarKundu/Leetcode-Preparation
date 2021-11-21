
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int temp = capacity, count = 0;
        for (int i = 0; i < plants.size(); i++) {
            if (capacity < plants[i]) {
                count += i + i;
                capacity = temp;
                // cout << "COunt" << " " << count << endl;
                
            }
            count++;
            // cout << count << endl;
            capacity -= plants[i];
        }
        return count;
    }
};