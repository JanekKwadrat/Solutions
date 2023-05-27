/*  Jan Zakrzewski
    https://codeforces.com/contest/1805/problem/A */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e3+10;
int t, n, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        s = 0;
        for(int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            s ^= a;
        }

        if(n % 2 == 1) cout << s << '\n';
        else if(s == 0) cout << "137\n";
        else cout << "-1\n";
    }

    return 0;
}