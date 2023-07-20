/*  Jan Zakrzewski
    https://codeforces.com/contest/1822/problem/G2 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200'010;

int t, n;
int a[N];
long long X;
unordered_multiset<int> S;
unordered_set<int> done;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        S.clear();
        done.clear();
        ans = 0;
        X = 0;

        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            S.insert(a[i]);
            X = max(X, (long long) a[i]);
        }

        for(int itr = 1; itr <= n; ++itr) {
            long long i = a[itr];
            if(done.count(i) > 0) continue;
            done.insert(i);

            ans += (long long) S.count(i) * (S.count(i) - 1) * (S.count(i) - 2);

            for(long long b = 2;; ++b) {
                long long j = i * b;
                long long k = j * b;
                if(k > X) break;

                ans += (long long) S.count(i) * S.count(j) * S.count(k);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}