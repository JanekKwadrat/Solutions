#include <bits/stdc++.h>
using namespace std;

int constexpr MOD = 1e9+7;
int constexpr HALF = (MOD + 1) / 2;
int constexpr N = 1e6 + 100;
int t;
int n, m, k;
int ans;

int factorial[N];

int modInverse(int, int);
inline int inverse(int x) {
    return modInverse(x, MOD);
}

inline int binomial(int a, int b) {
    if(b < 0) return 0;
    if(b > a) return 0;
    int ans = 1;
    ans = (long long)ans * factorial[a] % MOD;
    ans = (long long)ans * inverse(factorial[b]) % MOD;
    ans = (long long)ans * inverse(factorial[a-b]) % MOD;
    return ans;
}

int f(int n, int m) {
    if(m == 0) return 0;
    if(m == n) return n;

    int ans = 0;
    for(int i = 1; i <= m; ++i) {
        ans = ((long long)binomial(n-1, m-i) * (2*i-1) + ans) % MOD;
    }

    for(int i = 0; i < n-1; ++i) {
        ans = (long long)ans * HALF % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    factorial[0] = 1;
    for(int i = 1; i < N; ++i) factorial[i] = (long long)factorial[i-1] * i % MOD;

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        ans = (long long)f(n, m) * k % MOD;
        cout << ans << '\n';
    }

    return 0;
}

// from https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
