#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 2e9;
int constexpr N = 510;
int n, l, k;
int d[N], a[N];
int ans[N][N]; // ans[i][m] = What's the answer for the signs [i..n] assuming at least m signs have to be preserved? 1 <= i <= n, 1 <= m <= n-i+1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> k;
    for(int i = 1; i <= n; ++i) cin >> d[i];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ans[n][1] = (l - d[n]) * a[n];
    for(int i = 2; i <= n; ++i) ans[n][i] = INF;

    for(int i = n-1; i >= 1; --i) {
        ans[i][1] = (l - d[i]) * a[i];
        for(int m = 2; m <= n; ++m) {
            ans[i][m] = INF;
            for(int j = i+1; j <= n; ++j) {
                if(ans[j][m-1] >= INF) continue;
                ans[i][m] = min(ans[i][m], ans[j][m-1] + (d[j] - d[i]) * a[i]);
            }
        }
        for(int m = n-1; m >= 1; --m) ans[i][m] = min(ans[i][m], ans[i][m+1]);
    }

    cout << ans[1][n-k] << '\n';

    return 0;
}
