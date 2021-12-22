//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &arr, int r, int c){
        // code here    
        int low = 1, high = 2000;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < r; i++) {
                cnt += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
            }
            if (cnt <= (r * c) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends