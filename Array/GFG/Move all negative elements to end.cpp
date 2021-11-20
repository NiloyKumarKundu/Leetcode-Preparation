class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        int neg[n], pos[n];

        memset(neg, 0, sizeof(neg));
        memset(pos, -1, sizeof(pos));
        int negidx = 0, posidx = 0;
        for(int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos[posidx++] = arr[i];
            } else {
                neg[negidx++] = arr[i];
            }
        }

        // for (int i = 0; i < 5; i++) {
        //     cout << pos[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < 3; i++) {
        //     cout << neg[i] << " ";
        // }
        // cout << endl;

        int i = 0;
        while (pos[i] >= 0) {
            arr[i] = pos[i];
            i++;
        }
        negidx = 0;
        for (; i < n; i++) {
            arr[i] = neg[negidx++];
        }
    }
};