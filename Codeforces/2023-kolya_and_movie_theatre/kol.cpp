/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/E */

#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t;
int n, m, d;
int a[N];

long long ans;
long long sum;
priority_queue<int> small;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> d;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        ans = 0;
        sum = 0;
        while(small.size() > 0) small.pop();

        for(int i = 1; i <= n; ++i) {
            if(a[i] > 0) {
                sum += a[i];
                small.push(-a[i]);
                if(small.size() > m) {
                    sum -= -small.top();
                    small.pop();
                }
            }
            ans = max(ans, sum - (long long) d * i);
        }

        cout << ans << '\n';
    }

    return 0;
}
