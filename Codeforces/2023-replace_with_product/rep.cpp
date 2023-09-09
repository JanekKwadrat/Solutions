/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/G
    Solved with https://codeforces.com/blog/entry/120165 */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t, n;
int a[N];

int constexpr KAPPA = 20;
int constexpr INFTY = 1 << KAPPA;
int m, friends[N];
int product;
inline int mul(int x, int y) {
    return min((long long) x * y, (long long) INFTY);
}

int prefix_product[N];
int prefix_sum[N];

pair<int, pair<int, int>> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        m = 0, product = 1;
        for(int i = 1; i <= n; ++i) {
            if(a[i] > 1) {
                friends[m++] = i;
                product = mul(product, a[i]);
            }
        }

        if(m == 0) cout << "1 1\n";
        else if(product == INFTY) cout << friends[0] << ' ' << friends[m-1] << '\n';
        else {
            prefix_sum[0] = 0;
            prefix_product[0] = 1;
            for(int i = 1; i <= n; ++i) {
                prefix_sum[i] = prefix_sum[i-1] + a[i];
                prefix_product[i] = prefix_product[i-1] * a[i];
            }

            ans.first = -1;
            for(int i = 0; i < m; ++i) {
                for(int j = i; j < m; ++j) {
                    int l = friends[i];
                    int r = friends[j];
                    int nans = (prefix_product[r] / prefix_product[l-1]) - (prefix_sum[r] - prefix_sum[l-1]);
                    ans = max(ans, { nans, { l, r } });
                }
            }

            cout << ans.second.first << ' ' << ans.second.second << '\n';
        }
    }

    return 0;
}
