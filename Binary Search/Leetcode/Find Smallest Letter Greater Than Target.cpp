class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size();
        char ans = letters[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] == target) {
                left = mid + 1;
            } else if (letters[mid] < target) {
                left = mid + 1;
            } else {
                ans = letters[mid];
                right = mid - 1;
            }
        }
        return ans;
    }
};