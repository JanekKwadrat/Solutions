/*  Jan Zakrzewski
    https://codeforces.com/contest/1805/problem/B */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
int t, n;
char s[N], m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> s;
        m = 'z';
        for(int i = 0; i < n; ++i) m = min(m, s[i]);
        for(int i = n-1; i >= 0; --i) {
            if(s[i] != m) continue;
            for(; i >= 1; --i) {
                s[i] = s[i-1];
            }
            break;
        }
        s[0] = m;
        cout << s << '\n';
    }

    return 0;
}