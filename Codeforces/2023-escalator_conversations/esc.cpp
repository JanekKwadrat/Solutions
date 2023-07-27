/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/0 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100;
int t;
int n, m, k, H;
int h[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> k >> H;
        for(int i = 1; i <= n; ++i) cin >> h[i];

        ans = 0;
        for(int i = 1; i <= n; ++i) {
            int d = abs(H - h[i]);
            if(d % k != 0) continue;
            if(d / k >= m) continue;
            if(d / k <= 0) continue;
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}