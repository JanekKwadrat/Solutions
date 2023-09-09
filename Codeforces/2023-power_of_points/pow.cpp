/*  Jan Zakrzewski
    https://codeforces.com/contest/1857/problem/E */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t, n;
int x[N];
long long answer[N];

pair<int, int> sth[N];
long long sums[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> x[i];
            sth[i] = make_pair((long long) x[i], i);
        }
        sort(&sth[1], &sth[n]+1);

        sums[0] = 0;
        for(int i = 1; i <= n; ++i) sums[i] = sth[i].first + sums[i-1];
        for(int i = 1; i <= n; ++i) {
            answer[sth[i].second] =
                (long long)i * sth[i].first - sums[i] +
                (sums[n] - sums[i]) - (long long)(n - i) * sth[i].first +
                n;
        }

        for(int i = 1; i <= n; ++i) cout << answer[i] << ' ';
        cout << '\n';
    }

    return 0;
}
