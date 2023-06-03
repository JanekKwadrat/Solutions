/*  Jan Zakrzewski
    https://codeforces.com/contest/1839/problem/A */

#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        ans = (n - 1 + k - 1) / k + 1;
        cout << ans << '\n';
    }

    return 0;
}