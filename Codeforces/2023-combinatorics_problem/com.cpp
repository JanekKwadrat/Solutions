/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1832/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int M = 998'244'353;
constexpr int N = 1e7+10;
constexpr int K = 6; // K > k for all possible k
int n, L;
int a[N];
int B[K][N];
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    {
        int x, y, m;
        cin >> a[1] >> x >> y >> m;
        for(int i = 2; i <= n; ++i) a[i] = ((long long) a[i-1] * x + y) % m;
    }
    cin >> L;

    B[0][1] = a[1];
    for(int i = 2; i <= n; ++i) B[0][i] = (B[0][i-1] + a[i]) % M;

    for(int k = 1; k <= L; ++k) {
        if(k <= 1) B[k][1] = a[1];
        else B[k][1] = 0;
        for(int i = 1; i <= n; ++i) {
            B[k][i] = (B[k-1][i-1] + B[k][i-1]) % M;
            if(k <= 1) B[k][i] = (B[k][i] + a[i]) % M;
        }
    }

    ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans ^= (long long) B[L][i] * i;
    }

    cout << ans << '\n';

    return 0;
}