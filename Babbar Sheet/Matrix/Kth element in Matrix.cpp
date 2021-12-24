// 1st Approach

// Time Complixity: O(2n * log(max_value))

// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low = mat[0][0], high = mat[n - 1][n - 1];
  int ans = 0;
  
  
  while (low <= high) {
      int mid = low + (high - low) / 2;
      int count = 0;
      int i = n - 1, j = 0;
      while (i >= 0 && j < n) {
          if (mat[i][j] > mid) {
              i--;
          } else {
              count += i + 1;
              j++;
          }
      }
      if (count < k) {
          low = mid + 1;
      } else {
          ans = mid;
          high = mid - 1;
      }
  }
  
  return ans;
}




// 2nd Approach


// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int low = mat[0][0], high = mat[n - 1][n - 1];
  int mid = -1;
  
  while (low <= high) {
      mid = low + (high - low) / 2;
      int count = 0, j = 0;
      for (int i = 0; i < n; i++) {
          j = n - 1;
          while (j >= 0 && mat[i][j] > mid) {
              j--;
          }
          count += j + 1;
      }
      if (count < k) {
          low = mid + 1;
      } else {
          high = mid - 1;
      }
  }
  
  return low;
}



