/*  Jan Zakrzewski
    https://codeforces.com/contest/1828/problem/A */

#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cout << 2 * i << ' ';
        cout << '\n';
    }

    return 0;
}