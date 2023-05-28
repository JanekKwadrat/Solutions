/*  Jan Zakrzewski
    https://codeforces.com/contest/1805/problem/C */

/*
    ax^2 + bx + c > kx
    (b-k)^2-4ac < 0
    |b-k| < 2sqrt(ac)
    -2sqrt(ac) < b - k < 2sqrt(ac)
    -2sqrt(ac)+b < k < 2sqrt(ac)+b
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
constexpr long double INF = 1e12;

int t, n, m;
long double k[N]; // n lines
long double a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> k[i];
        n++; k[n] = INF;
        sort(&k[1], &k[n]+1);
        //for(int i = 1; i <= n; ++i) cout << k[i] << ' '; cout << '\n';

        for(int i = 1; i <= m; ++i) {
            cin >> a >> b >> c;
            long double left = -2 * sqrtl(a * c) + b;
            long double right = 2 * sqrtl(a * c) + b;

            long double our_k = *upper_bound(&k[1], &k[n]+1, left);

            if(our_k > left && our_k < right) cout << "YES\n" << (long long) our_k << '\n';
            else cout << "NO\n";
            //cout << left << ' ' << right << ' ' << our_k << '\n';
        }
    }

    return 0;
}