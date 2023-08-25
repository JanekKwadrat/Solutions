/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/B */

#include <bits/stdc++.h>
using namespace std;

int t;
constexpr int N = 4e5+100;
int n, m;
int b[N], a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> b[i];

        a[1] = b[1];
        m = 1;
        for(int i = 2; i <= n; ++i) {
            if(b[i-1] > b[i]) {
                a[++m] = 1;
            }
            a[++m] = b[i];
        }

        cout << m << '\n';
        for(int j = 1; j <= m; ++j) cout << a[j] << ' ';
        cout << '\n';
    }

    return 0;
}
