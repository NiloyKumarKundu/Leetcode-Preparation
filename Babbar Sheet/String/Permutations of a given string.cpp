// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	   // If the length of a given string is length N, then the permutation of the given string will be N!.
	   
	   // The height/depth of the tree is always equal to the length of the string.
	   
	   // Time complexity: O(Time to print one permutaition * No of permutation) = O(N * N!)

        // Space Complexity: O(1)
	              
        vector<string> ans;
	
	    void calc(string s, int l, int r) {
	        if (l == r) {
	            ans.push_back(s);
	        } else {
	            for (int i = l; i <= r; i++) {
	                swap(s[l], s[i]);
	                calc(s, l + 1, r);
	                swap(s[l], s[i]);
	            }
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    
		    int l = 0, r = S.length() - 1;
		    calc(S, l, r);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends