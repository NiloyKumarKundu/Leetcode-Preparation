// Time: O(N) Space: O(1) More optimised

pair<long long, long long> getMinMax(long long arr[], int n) {
    int maxi, mini, i;
    if (n % 2 == 0) {
        maxi = max(arr[0], arr[1]);  
        mini = min(arr[0], arr[1]); 
        i = 2;
    } else {
        maxi = mini = arr[0];
        i = 1;
    }
    
    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
            if (arr[i + 1] < mini) {
                mini = arr[i + 1];
            }
        } else {
            if (arr[i + 1] > maxi) {
                maxi = arr[i + 1];
            }
            if (arr[i] < mini) {
                mini = arr[i];
            }
        }
        i += 2;
    }
    return {mini, maxi};
}


// Time: O(N) Space: O(1)

pair<long long, long long> getMinMax(long long a[], int n) {
    int maxi = max(a[0], a[1]);
    int mini = min(a[0], a[1]);
    
    for (int i = 2; i < n; i++) {
        if (a[i] > maxi) {
            maxi = a[i];
        } else if (a[i] < mini) {
            mini = a[i];
        }
    }
    
    return {mini, maxi};
}