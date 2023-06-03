/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1833/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n;
int a[N];
bool ok[N];
int d, C;
int color[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        d = 0;
        for(int i = 1; i <= n; ++i) {
            ok[i] = false;
            if(a[a[i]] == i) {
                ok[i] = true;
                d++;
            }
        }
        d /= 2;

        C = 0;
        function<int(int)> Color = [&](int i) -> int {
            if(color[i] == -1) {
                color[i] = i;
                color[i] = Color(a[i]);
            }
            return color[i];
        };
        for(int i = 1; i <= n; ++i) color[i] = -1;
        for(int i = 1; i <= n; ++i) Color(i);
        for(int i = 1; i <= n; ++i) {
            if(color[i] == i)
                C++;
        }

        cout << C - max(d - 1, 0) << ' ';
        cout << C << '\n';
    }

    return 0;
}