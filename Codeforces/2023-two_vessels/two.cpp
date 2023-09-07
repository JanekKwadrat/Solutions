/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/A */
#include <bits/stdc++.h>
using namespace std;

int t;
double a, b, c;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        ans = ceil(abs((a - b) / 2) / c);
        cout << ans << '\n';
    }

    return 0;
}
