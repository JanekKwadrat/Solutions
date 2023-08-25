/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/C */

#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t, n;
int a[N], b[N];
bool ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        ok = a[1] <= n;
        if(!ok) {
            cout << "NO\n";
            continue;
        }

        for(int i = 1; i <= n; ++i) b[i] = 0;
        for(int i = 1; i <= n; ++i) {
            b[1]++;
            b[a[i]+1]--;
        }

        for(int i = 2; i <= n; ++i) b[i] += b[i-1];
        for(int i = 1; i <= n; ++i) ok = ok && a[i] == b[i];

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
