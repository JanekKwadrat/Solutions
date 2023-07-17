/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1848/F */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1'200'000;
int n;
int a[N], b[N];

bool ok;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    ok = true;
    for(int i = 0; i < n; ++i) ok = ok && a[i] == 0;

    if(ok) cout << "0\n";
    else {

        ans = 0;
        while(true) {
            int k = n;
            while(true) {
                k /= 2;
                if(k == 0) break;
                ok = true;
                for(int i = 0; i < n; ++i)
                    ok = ok && (a[i] ^ a[(i+k) % n]) == 0;
                if(!ok) break;
            }

            if(k == 0) {
                ans++;
                break;
            } else {
                ans += k;
                for(int i = 0; i < n; ++i)
                    b[i] = a[i] ^ a[(i+k) % n];
                for(int i = 0; i < n; ++i)
                    a[i] = b[i];
            }
        }

        cout << ans << '\n';

    }

    return 0;
}