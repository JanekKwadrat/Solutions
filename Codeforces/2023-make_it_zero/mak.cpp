/*  Jan Zakrzewski
    https://codeforces.com/contest/1869/problem/A */
#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) { int a; cin >> a; }

        if(n % 2 == 0) {
            cout << "2\n";
            cout << "1 " << n << '\n';
            cout << "1 " << n << '\n';
        } else {
            cout << "4\n";
            cout << "2 " << n << '\n';
            cout << "2 " << n << '\n';
            cout << "1 2\n";
            cout << "1 2\n";
        }
    }

    return 0;
}
