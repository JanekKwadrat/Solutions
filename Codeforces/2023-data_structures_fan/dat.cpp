/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/E */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e5+10;
int t, n, q;
int a[N];
char s[N];
int sum[N];
int zeros, ones;
int k, l, r, g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        cin >> s+1;

        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] ^ a[i];
        }

        zeros = 0, ones = 0;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == '0') zeros ^= a[i];
            else ones ^= a[i];
        }

        cin >> q;
        while(q--) {
            cin >> k;
            if(k == 1) {
                cin >> l >> r;
                int flip = sum[r] ^ sum[l-1];
                zeros ^= flip;
                ones ^= flip;
            } else if(k == 2) {
                cin >> g;
                if(g == 0) cout << zeros << ' ';
                else cout << ones << ' ';
            } else cout << "FUCKEDUP\n";
        }
        cout << '\n';
    }

    return 0;
}
