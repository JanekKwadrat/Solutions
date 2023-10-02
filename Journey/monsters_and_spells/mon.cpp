#include <bits/stdc++.h>
using namespace std;

long long tri(long long x) {
    return x * (x + 1) / 2;
}

int constexpr N = 200;
int t, n;
int k[N], h[N];
int p, q;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> k[i];
        for(int i = 1; i <= n; ++i) cin >> h[i];

        ans = 0;
        k[0] = 0, h[0] = 0;

        for(int i = n; i >= 0; --i) {
            if(i == n) {
                q = k[i];
                p = k[i];
            } else if(k[i] < p) {
                ans += tri(q - p + 1);
                q = k[i];
                p = k[i];
            }
            p = min(p, k[i] - h[i] + 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
