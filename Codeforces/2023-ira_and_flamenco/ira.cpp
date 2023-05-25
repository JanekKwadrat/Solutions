/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1833/F */

#include <bits/stdc++.h>
using namespace std;

constexpr int M = 1e9+7;
constexpr int N = 2e5+10;
constexpr int D = 1 << 18; // D >= N

int t, n, m;
int a[N];

int k, d;
pair<int, int> x[N];
int Tree[2 * D];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(&a[1], &a[n]+1);

        k = 0;
        for(int i = 1; i <= n; ++i) {
            if(k > 0 && x[k-1].first == a[i]) x[k-1].second++;
            else {
                x[k] = make_pair(a[i], 1);
                k++;
            }
        }

        d = 1; while(d < k) d *= 2;
        for(int i = d; i < 2*d; ++i) Tree[i] = 1;
        for(int i = 0; i < k; ++i) Tree[d + i] = x[i].second;
        for(int i = d-1; i >= 1; --i) Tree[i] = (long long) Tree[2*i] * Tree[2*i+1] % M;

        ans = 0;
        int p = 0, q = m-1;
        while(true) {
            int ans1 = 0;
            if(x[q].first - x[p].first == m-1) {
                ans1 = 1;
                int i = p + d, j = q + d;
                ans1 = (long long) ans1 * Tree[i] % M;
                if(j != i) ans1 = (long long) ans1 * Tree[j] % M;
                while(i / 2 != j / 2) {
                    if(i % 2 == 0) ans1 = (long long) ans1 * Tree[i + 1] % M;
                    if(j % 2 == 1) ans1 = (long long) ans1 * Tree[j - 1] % M;

                    i /= 2;
                    j /= 2;
                }
            }
            ans = (ans + ans1) % M;

            p++, q++;
            if(q >= k) break;
        }

        cout << ans << '\n';
    }

    return 0;
}