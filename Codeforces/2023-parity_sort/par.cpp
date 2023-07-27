/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/B */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n;
int a[N], b[N];
bool ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        for(int i = 1; i <= n; ++i) b[i] = a[i];
        sort(&b[1], &b[n]+1);
        ans = true;
        for(int i = 1; i <= n; ++i) ans = ans && (a[i] + b[i]) % 2 == 0;

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}