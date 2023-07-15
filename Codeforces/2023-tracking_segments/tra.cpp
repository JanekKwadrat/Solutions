/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1843/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'010;

int t;
int n, m, q;
int l[N], r[N];
int sum[N];
int queries[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> l[i] >> r[i];
        }
        cin >> q;
        for(int i = 1; i <= q; ++i) {
            cin >> queries[i];
        }

        function<bool(int)> Okay = [&](int k) -> bool {
            for(int i = 0; i <= n; ++i) sum[i] = 0;
            for(int i = 1; i <= k; ++i) sum[queries[i]] = 1;
            for(int i = 1; i <= n; ++i) sum[i] += sum[i-1];
            bool ans = false;
            for(int i = 1; i <= m; ++i) ans = ans || 2 * (sum[r[i]] - sum[l[i]-1]) > r[i] - l[i] + 1;
            return ans;
        };

        int a = 0, b = q+1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(Okay(mid)) b = mid;
            else a = mid;
        }
        
        if(b > q) cout << "-1\n";
        else cout << b << '\n';
    }

    return 0;
}