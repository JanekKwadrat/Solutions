/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1848/C */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
int t, n;
int a[N], b[N];
int ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];

        ok = -1;
        for(int i = 1; i <= n; ++i) {
            int d = gcd(a[i], b[i]);
            if(d == 0) continue;
            a[i] /= d;
            b[i] /= d;
            int C = (a[i] % 2) + 2 * (b[i] % 2);
            if(ok == -1) ok = C;
            else if(ok != C) ok = 0;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}