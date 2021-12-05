// Time Complixity: O(3N)
// Space Complixity: O(N)

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      set<int> hashSet;
      for (int i = 0; i < N; i++) {
          hashSet.insert(arr[i]);
      }
      
      int longestStreak = 0;  // maximum of all consecutive sequences
      
      for (int i = 0; i < N; i++) {
          if (!hashSet.count(arr[i] - 1)) {
              int currentNum = arr[i];
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