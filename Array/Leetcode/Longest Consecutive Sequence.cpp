// Time Complixity: O(N)
// Space Complixity: O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for (int i : nums) {
            hashSet.insert(i);
        }
        int longestStreak = 0;
        
        for (int num : nums) {
            if (!hashSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                while (hashSet.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};