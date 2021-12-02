// Time Complixity: O(N)
// Space Complixity: O(N)

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos, neg;
	    for (int i = 0; i < n; i++) {
	        if (arr[i] >= 0) {
	            pos.push_back(arr[i]);
	        } else {
	            neg.push_back(arr[i]);
	        }
	    }
	    
	    int size = min(pos.size(), neg.size());
	    int i = 0;
	    int posIndex = 0, negIndex = 0;
	    while (i != (size * 2)) {
	        if (i % 2) {
	            arr[i] = neg[negIndex++];
	        } else {
	            arr[i] = pos[posIndex++];
	        }
	        i++;
	    }
	    
	    
	    if (posIndex != pos.size()) {
	        for (int j = posIndex; j < pos.size(); j++) {
	            arr[i] = pos[j];
	            i++;
	        }
	    } else {
	        for (int j = negIndex; j < neg.size(); j++) {
	            arr[i] = neg[j];
	            i++;
	        }
	    }
	}
};