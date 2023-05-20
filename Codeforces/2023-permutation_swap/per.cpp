/*  Jan Zakrzewski
    https://codeforces.com/contest/1828/problem/B */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100'000 + 10;
int t, n;
int p, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; ++i) {
            cin >> p; p--;
            ans = gcd(ans, p - i);
        }
        cout << ans << '\n';
    }

    return 0;
}