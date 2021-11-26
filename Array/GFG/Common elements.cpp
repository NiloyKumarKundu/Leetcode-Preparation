// Time Complixity: O(n1 + n2 + n3)
// Space Complixity: O(1)
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i = 0, j = 0, k = 0;
            vector<int> ans;
            
            while (i < n1 && j < n2 && k < n3) {
                if (A[i] == B[j] && B[j] == C[k]) {
                    ans.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                } else if (A[i] < B[j]) {
                    i++;
                } else if (B[j] < C[k]) {
                    j++;
                } else {
                    k++;
                }
                int xx = A[i - 1];
                while (A[i] == xx) i++;
                xx = B[j - 1];
                while (B[j] == xx) j++;
                xx = C[k - 1];
                while (C[k] == xx) k++;
            }
            
            if (ans.size() == 0) ans.push_back(-1);
            return ans;
            
        }
};




// Time Complixity: O(n1 + n2 + n3)
// Space Complixity: O(n1 + n2 + n3)

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            unordered_map<int, int> mp1, mp2, mp3;
            vector<int> v;
            for (int i = 0; i < n1; i++) {
                mp1[A[i]]++;
            }
            
            for (int i = 0; i < n2; i++) {
                mp2[B[i]]++;
            }
            
            for (int i = 0; i < n3; i++) {
                mp3[C[i]]++;
            }
            
            for (int i = 0; i < n1; i++) {
                if (mp1[A[i]] and mp2[A[i]] and mp3[A[i]]) {
                    v.push_back(A[i]);
                    mp1[A[i]] = 0;
                }
            }
            return v;
        }
};