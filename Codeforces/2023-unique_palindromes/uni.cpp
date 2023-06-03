/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1823/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
constexpr int K = 100;
int t, n, k;
vector<pair<int,int>> xcs;

char s[N];
bool ans;
int m, score;
char letter, xyz;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        xcs.resize(k);
        for(int i = 1; i <= k; ++i) cin >> xcs[i-1].first;
        for(int i = 1; i <= k; ++i) cin >> xcs[i-1].second;

        s[1] = 'x', s[2] = 'y', s[3] = 'z';
        m = 3, score = 3, letter = 'a', xyz = 'x';

        ans = true;
        for(auto elm : xcs) {
            int x = elm.first, c = elm.second;

            while(score < c) {
                m++;
                if(m > x) {
                    ans = false;
                    break;
                }
                s[m] = letter;
                score++;
            }
            if(!ans) break;
            while(m < x) {
                m++;
                s[m] = xyz;
                xyz = (xyz - 'x' + 1) % 3 + 'x';
            }

            letter++;
        }

        if(!ans) cout << "NO\n";
        else {
            cout << "YES\n";
            s[n+1] = '\0';
            cout << s + 1 << '\n';
        }
    }

    return 0;
}