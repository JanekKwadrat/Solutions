/*  Jan Zakrzewski
    https://codeforces.com/contest/1869/problem/B */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5 + 10;
int t;
int n, k, a, b;
struct City { long long x, y; } city[N];
long long a_m, b_m, a_b;
long long answer;

inline long long dst(City u, City v) {
    return abs(u.x - v.x) + abs(u.y - v.y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> a >> b;
        for(int i = 1; i <= n; ++i) {
            cin >> city[i].x;
            cin >> city[i].y;
        }

        a_m = INT64_MAX / 10;
        b_m = INT64_MAX / 10;
        a_b = dst(city[a], city[b]);
        for(int i = 1; i <= k; ++i) {
            a_m = min(a_m, dst(city[a], city[i]));
            b_m = min(b_m, dst(city[b], city[i]));
        }

        answer = min(a_m + b_m, a_b);
        cout << answer << '\n';
    }

    return 0;
}
