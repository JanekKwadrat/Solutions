#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e5+10;
int constexpr L = 'z' - 'a' + 1;
int t;
int n;
string s[N];

bool ans;
bool triples[L*L*L];
int double_ending_with[L*L];
int triple_ending_with[L*L];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> s[i];
        ans = false;

        for(int i = 1; i <= n; ++i) {
            string ss = s[i];
            reverse(ss.begin(), ss.end());
            if(s[i] == ss) ans = true;
        }

        for(int i = 0; i < L*L*L; ++i) triples[i] = false;
        for(int i = 1; i <= n; ++i) {
            if(s[i].length() != 3) continue;
            triples[(s[i][0]-'a')+L*(s[i][1]-'a')+L*L*(s[i][2]-'a')] = true;
        }
        for(int i = 1; i <= n; ++i) {
            if(s[i].length() != 3) continue;
            if(triples[(s[i][2]-'a')+L*(s[i][1]-'a')+L*L*(s[i][0]-'a')])
                ans = true;
        }

        for(int i = 0; i < L*L; ++i) {
            double_ending_with[i] = 0;
            triple_ending_with[i] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            if(s[i].length() == 2) {
                double_ending_with[(s[i][0]-'a')+L*(s[i][1]-'a')] = i;
            } else if(s[i].length() == 3) {
                triple_ending_with[(s[i][1]-'a')+L*(s[i][2]-'a')] = i;
            }
        }
        for(int i = 1; i <= n; ++i) {
            if(s[i].length() == 2) {
                if(double_ending_with[(s[i][1]-'a')+L*(s[i][0]-'a')] > i) ans = true;
                if(triple_ending_with[(s[i][1]-'a')+L*(s[i][0]-'a')] > i) ans = true;
            } else if(s[i].length() == 3) {
                if(double_ending_with[(s[i][1]-'a')+L*(s[i][0]-'a')] > i) ans = true;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
