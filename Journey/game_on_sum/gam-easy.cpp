#include <bits/stdc++.h>
using namespace std;

int constexpr MOD = 1e9+7;
int constexpr HALF = (MOD + 1) / 2;
int t;
int n, m, k;
int ans;

int constexpr X = 1e9;
unordered_map<long long,int> memo;
int f(int n, int m) {
    if(m == 0) return 0;
    if(m == n) return n;

    long long key = (long long)n * X + m;
    if(memo.count(key)) return memo[key];

    int ans = (long long)(f(n-1, m) + f(n-1, m-1)) * HALF % MOD;
    memo[key] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        ans = (long long)f(n, m) * k % MOD;
        cout << ans << '\n';
    }

    return 0;
}
