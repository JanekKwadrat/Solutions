/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n;
long long a[N];

bool ans;
bool seen[N];
vector<long long> missing;
long long top;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n-1; ++i) cin >> a[i];
        a[0];

        for(int i = 1; i <= n; ++i) seen[i] = false;
        missing.clear();
        for(int i = 1; i <= n-1; ++i) {
            long long d = a[i] - a[i-1];
            if(d <= n) seen[d] = true;
        }
        for(int i = 1; i <= n; ++i) {
            if(seen[i]) continue;
            missing.push_back(i);
        }
        top = (long long) n * (n + 1) / 2;

        if(a[n-1] < top) {
            ans = missing.size() == 1 && a[n-1] + missing[0] == top;
        } else {
            ans = missing.size() == 2 && a[n-1] == top;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}