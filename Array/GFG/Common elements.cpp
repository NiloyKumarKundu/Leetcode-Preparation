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