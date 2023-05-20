/*  Jan Zakrzewski
    https://codeforces.com/contest/1828/problem/C */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200'000+10;
constexpr int M = 1e9 + 7;
int t, n;
int a[N], b[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];

        sort(&a[1], &a[n]+1);
        sort(&b[1], &b[n]+1);

        ans = 1;
        int p = 1, q = 1;
        while(p <= n) {
            if(q <= n && a[p] > b[q]) q++;
            else {
                ans = (long long) ans * (q - p) % M;
                p++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}