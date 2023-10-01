#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t;
int n;
long long k;
long long sum;
int a[N];

long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        sort(&a[1], &a[n]+1);
        sum = 0;
        for(int i = 1; i <= n; ++i) sum += a[i];

        ans = INT64_MAX;

        sum -= a[1];
        for(int i = n; i >= 1; --i) {
            // consider all the numbers [2..i] to be unchanged
            // sum holds their sum
            long long atmost = floorl((long double)(k - sum) / (long double)(n - i + 1));
            long long ans1 = max(0ll, a[1] - atmost);
            ans1 += n - i;
            ans = min(ans, ans1);

            sum -= a[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
