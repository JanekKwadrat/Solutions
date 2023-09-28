/*  Jan Zakrzewski
    https://www.codechef.com/START101D/problems/SMARTER */

#include <bits/stdc++.h>
using namespace std;

int t;
int l, v1, v2;
int ans;

inline int ile(int l, int v) {
    return (l + v - 1) / v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> l >> v1 >> v2;

        ans = ile(l, v1) - ile(l, v2) - 1;

        cout << ans << '\n';
    }

    return 0;
}
