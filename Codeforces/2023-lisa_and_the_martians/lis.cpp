/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/F */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t;
int n, k;
uint32_t a[N];

uint32_t answer, shot;
unordered_multiset<uint32_t> S;
uint32_t sth;

int itr, jtr;
uint32_t X;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        answer = 0;
        sth = 0;
        for(int b = k-1; b >= 0; --b) {
            shot = answer ^ (1 << b);
            S.clear();
            for(int i = 1; i <= n; ++i) S.insert(a[i] & shot);
            for(int i = 1; i <= n; ++i) {
                if(S.count(a[i] & shot) < 2) continue;
                answer = shot;
                sth = a[i] & answer;
                break;
            }
        }

        for(int i = 1; i <= n; ++i) {
            if((answer & a[i]) != sth) continue;
            itr = i;
            break;
        }
        for(int j = n; j >= 1; --j) {
            if((answer & a[j]) != sth) continue;
            jtr = j;
            break;
        }

        X = answer ^ a[itr];

        cout << itr << ' ' << jtr << ' ' << X << '\n';
        //cout << "= " << ((a[itr] ^ X) & (a[jtr] ^ X)) << ' ' << answer << '\n';
    }

    return 0;
}