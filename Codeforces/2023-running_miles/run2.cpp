/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1826/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'010;
int t, n;
int a[N];
int l[N], r[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        l[1] = 0;
        for(int i = 2; i <= n; ++i) l[i] = max(l[i-1]-1, a[i-1]-1);

        r[n] = 0;
        for(int i = n-1; i >= 1; --i) r[i] = max(r[i+1]-1, a[i+1]-1);

        ans = 0;
        for(int i = 1; i <= n; ++i) ans = max(ans, l[i] + a[i] + r[i]);

        cout << ans << '\n';
    }

    return 0;
}