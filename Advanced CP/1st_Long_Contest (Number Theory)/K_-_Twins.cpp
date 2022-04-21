#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 1e7 + 123
#define MOD (int) 1e9 + 7
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define llu unsigned long long
using namespace std;
/* ----------------------------------------------------------------------------------- */

// Input/Output
#define fastInput ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

/* ----------------------------------------------------------------------------------- */



vi Primes;
vi segPrimes;

void sieve() {
    bool isPrime[mx];
    for (int i = 0; i < mx; i++) {
        isPrime[i] = true;
    }

    for (int i = 3; i * i < mx; i += 2) {
        if(isPrime[i]) {
            for (int j = i * i; j < mx; j += i) {
                isPrime[j] = false;
            }
        }
    }

    Primes.push_back(2);
    for (int i = 3; i < mx; i += 2) {
        if(isPrime[i]) {
            Primes.push_back(i);
        }
    }
}


void segmentedSieve(int l, int r) {
    int size = r - l + 1;
    bool isPrime[size];
    for (int i = 0; i < size; i++) {
        isPrime[i] = true;
    }
    if(l == 1)
        isPrime[0] = false;

    for (int i = 0; Primes[i] * (int) Primes[i] <= r; i++) {
        int currentPrime = Primes[i];

        // Just smaler or equal value to l
        int base = (l / currentPrime) * currentPrime;
        if(base < l) {
            base += currentPrime;
        }

        // Mark all multiples within L to R as false
        for (int j = base; j <= r; j += currentPrime) {
            isPrime[j - l] = false;
        }

        // There may be a case where base is itself a prime number 
        if(base == currentPrime) {
            isPrime[base - l] = true;
        }
    }

    for (int i = 0; i < size; i++) {
        if(isPrime[i]) {
            //cout << (i + l) << endl;
            segPrimes.push_back(i + l);
        }
    }
}


void solve() {
    int l, r;
    cin >> l >> r;
    segmentedSieve(l, r);

    int ans = 0;
    for (int i = 1; i < segPrimes.size(); i++) {
        int diff = abs(segPrimes[i] - segPrimes[i - 1]);
        if (diff == 2) {
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    // input();
    fastInput;
    sieve();
    solve();

    // __test {
    //     solve();
    // }

    // showTime;
    return 0;
}
