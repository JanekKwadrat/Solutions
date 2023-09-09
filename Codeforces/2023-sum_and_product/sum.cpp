/*  Jan Zakrzewski
    https://codeforces.com/contest/1857/problem/F */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t, n;
vector<long long> S;
int q;
long long x, y;
long long answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        while(n--) {
            int a; cin >> a;
            S.push_back(a);
        }
        sort(S.begin(), S.end());

        cin >> q;
        while(q--) {
            cin >> x >> y;

            long long d = x*x - 4*y;
            long long sqrtd;
            if(d < 0) sqrtd = -1;
            else {
                sqrtd = round(sqrtl(d));
                if(sqrtd * sqrtd != d) sqrtd = -1;
            }

            if(sqrtd == -1) cout << "0 ";
            else {
                long long ai = (x + sqrtd) / 2;
                long long aj = (x - sqrtd) / 2;
                long long ci = upper_bound(S.begin(), S.end(), ai) - lower_bound(S.begin(), S.end(), ai);
                long long cj = upper_bound(S.begin(), S.end(), aj) - lower_bound(S.begin(), S.end(), aj);
                if(ai != aj) cout << ci * cj << ' ';
                else cout << ci * (ci - 1) / 2 << ' ';
            }
        }
        cout << '\n';

        S.clear();
    }


    return 0;
}
