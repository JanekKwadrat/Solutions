/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/C */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n, k;
int c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> c[i];

        int p = 1, q = n, C;
        bool ok = true;

        C = 0;
        while(true) {
            if(c[p] == c[1]) C++;
            if(C >= k) break;
            p++;
            if(p > n) {
                ok = false;
                break;
            }
        }

        C = 0;
        while(true) {
            if(c[q] == c[n]) C++;
            if(C >= k) break;
            q--;
            if(q < 1) {
                ok = false;
                break;
            }
        }

        ok = ok && (p < q || c[1] == c[n]);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}