/********************** For Clock Wise ***********************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n;
	cin >> n; 
	int arr[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cin >> arr[i][j];
	    }
	}
	

	
	// Column Reverse inplace
	
	for (int i = 0; i < n; i++) {
	    int j = 0, k = n - 1;
	    while (j < k) {
	        swap(arr[j][i], arr[k][i]);
	        j++;
	        k--;
	    }
	}

	// Printing the array
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cout << arr[i][j] << " ";
	    }
	    cout << endl;
	}
	
	
	cout << endl;
		// transpose in place
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i; j++) {
	        swap(arr[i][j], arr[j][i]);
	    }
	}

	
	// Printing the array
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cout << arr[i][j] << " ";
	    }
	    cout << endl;
	}
	return 0;
}


/********************** For Anti Clock Wise ***********************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int n;
	cin >> n; 
	int arr[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cin >> arr[i][j];
	    }
	}
	
	// transpose in place
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i; j++) {
	        swap(arr[i][j], arr[j][i]);
	    }
	}
	
	// Printing the array
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cout << arr[i][j] << " ";
	    }
	    cout << endl;
	}
	
	// Column Reverse inplace
	
	for (int i = 0; i < n; i++) {
	    int j = 0, k = n - 1;
	    while (j < k) {
	        swap(arr[j][i], arr[k][i]);
	        j++;
	        k--;
	    }
	}
	cout << endl;
	// Printing the array
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cout << arr[i][j] << " ";
	    }
	    cout << endl;
	}
	return 0;
}