#include <bits/stdc++.h>
using namespace std;

int constexpr N = 3e5+10;
int constexpr M = 998244353;
int constexpr K = 30;
int n, a[N];
int ans;
int sum_even[K], count_even[K];
int sum_odd[K], count_odd[K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    ans = 0;
    for(int k = 0; k < K; ++k) {
        sum_even[k] = 0;
        count_even[k] = 0;
        sum_odd[k] = 0;
        count_odd[k] = 0;
    }

    for(int i = 1; i <= n; ++i) {
        for(int k = 0; k < K; ++k) {
            if(a[i] & (1 << k)) {
                swap(sum_even[k], sum_odd[k]);
                swap(count_even[k], count_odd[k]);
                count_odd[k]++;
            } else count_even[k]++;
            sum_even[k] = ((long long) sum_even[k] + count_even[k]) % M;
            sum_odd[k] = ((long long) sum_odd[k] + count_odd[k]) % M;
            ans = (ans + (long long) sum_odd[k] * (1 << k)) % M;
        }
    }

    cout << ans << '\n';

    return 0;
}
