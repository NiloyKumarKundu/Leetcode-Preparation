int max_sum(int A[],int N)
{
//Your code here
    int sum = 0, si = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        si += A[i] * i;
    }
    ans = si;
    
    for (int i = 0; i < N - 1; i++) {
        int sip1 = si + sum - (N * A[N - i - 1]);
        ans = max(ans, sip1);
        si = sip1;
    }
    return ans;
}