// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int start = 0, end = 1, low, high;
        
        for (int i = 1; i < S.length(); i++) {
            // even part
            low = i - 1;
            high = i;
            while (low >= 0 && high < S.length() && S[low] == S[high]) {
                if (high - low + 1 > end) {
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }
            
            
            // odd part
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < S.length() && S[low] == S[high]) {
                if (high - low + 1 > end) {
                    start = low;
                    end = high - low + 1;
                }
                low--;
                high++;
            }
        }
        
        string ans = S.substr(start, end);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends