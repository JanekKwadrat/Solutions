#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e6+10;
int constexpr X = 1e6;
int n, a[N];
vector<int> divisors[X+1]; // divisors[x] = list of all positive divisors of x, empty for x = 0
unsigned long long alpha_signature[X+1] = {}; // alpha_signature[x] = signature of the list of multiples a[i] of x, empty for x = 0
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 1; i <= X; ++i) {
        for(int j = i; j <= X; j += i) {
            divisors[j].push_back(i);
        }
    }

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        for(int d : divisors[a[i]]) {
            alpha_signature[d] *= 1'000'003;
            alpha_signature[d] += a[i];
        }
    }

    sort(&alpha_signature[0], &alpha_signature[X+1]);
    ans = unique(&alpha_signature[0], &alpha_signature[X+1]) - &alpha_signature[0];
    ans -= 1 + n;

    cout << ans << '\n';

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e6+10;
int constexpr X = 1e6;
int n, a[N];
vector<int> ppow_divisors[X+1];
vector<int> multiples_ppow[X+1];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i = 2; i < X; ++i) {
        if(ppow_divisors[i].size() > 0) continue;
        long long x = i;
        while(x < X) {
            for(int j = x; j < X; j += x) {
                ppow_divisors[j].push_back(x);
            }

            x *= i;
        }
    }
    for(int i = 1; i < X; ++i) ppow_divisors[i].push_back(1);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        for(int x : ppow_divisors[a[i]]) {
            multiples_ppow[x].push_back(a[i]);
        }
    }

    multiples_ppow[0].clear();
    sort(&multiples_ppow[0], &multiples_ppow[X]+1);
    ans = unique(&multiples_ppow[0], &multiples_ppow[X]+1) - &multiples_ppow[0];
    ans -= n + 1;

    cout << ans << '\n';

    return 0;
}
*/
