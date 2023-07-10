/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1845/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5+20;
int t, n;
int a[N];
pair<long long, long long> ans;
long long p, q;
long long best;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        p = 0, q = 0, best = 0;
        for(int i = 1; i <= n; ++i) p += a[i];
        ans = { max(0ll, p), 0ll };

        for(int i = n; i >= 1; --i) {
            p -= a[i];
            q += a[i];
            best = max(best, q);
            //cout << p << " " << best << "\n";
            ans = max(ans, { p + best, p });
        }

        cout << ans.second << "\n";
    }

    return 0;
}