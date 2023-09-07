/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/B */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 500;
int t, n;
int trap[N];
int ans, itr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < N; ++i){
            trap[i] = -1;
        }
        while(n--) {
            int d, s;
            cin >> d >> s;
            int ttrap = d + (s - 1) / 2;
            if(trap[d] == -1) trap[d] = ttrap;
            else trap[d] = min(trap[d], ttrap);
        }

        ans = N;
        itr = 1;
        while(itr <= ans) {
            if(trap[itr] != -1)
                ans = min(ans, trap[itr]);
            itr++;
        }
        cout << ans << '\n';
    }

    return 0;
}
