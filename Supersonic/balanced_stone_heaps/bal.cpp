#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t;
int n, h[N];
int available[N];
int p, q, m;
int ans;

bool solve(int threshold) {
    // Definitely, solve(0) is true and solve(1 << 30) is false

    for(int i = 1; i <= n; ++i) available[i] = 0;
    for(int i = n; i >= 1; --i) {
        available[i] += h[i] - threshold;
        if(h[i] < available[i]) available[i] = h[i];
        if(available[i] < 0) return false;
        if(i >= 3) {
            int d = available[i] / 3;
            available[i-2] += 2*d;
            available[i-1] += d;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> h[i];

        p = 0, q = (1 << 30);
        while(q - p > 1) {
            m = (p + q) / 2;
            if(solve(m)) p = m;
            else q = m;
        }
        ans = p;

        cout << ans << '\n';
    }

    return 0;
}
