/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1846/G */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e3;
int t, n, m;
std::string s;

int rudolf;
int czas[N];
int removes[N];
int appears[N];

int odleglosc[N];
priority_queue<pair<int, int>> Queue;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;

        cin >> s;
        rudolf = 0;
        for(int i = n-1; i >= 0; --i) rudolf = rudolf * 2 + s[i] - '0';
        
        for(int i = 1; i <= m; ++i) {
            cin >> czas[i];
            cin >> s; removes[i] = 0; for(int j = n-1; j >= 0; --j) removes[i] = removes[i] * 2 + s[j] - '0';
            cin >> s; appears[i] = 0; for(int j = n-1; j >= 0; --j) appears[i] = appears[i] * 2 + s[j] - '0';
        }

        while(Queue.size() > 0) Queue.pop();
        for(int i = 0; i < (1 << n); ++i) odleglosc[i] = INT32_MAX;

        Queue.push(make_pair(0, rudolf));
        while(Queue.size() > 0) {
            int u = Queue.top().second;
            int odl = -Queue.top().first;
            Queue.pop();
            if(odleglosc[u] < INT32_MAX) continue;
            odleglosc[u] = odl;
            for(int i = 1; i <= m; ++i) {
                int v = (u & ~removes[i]) | appears[i];
                int odle = odl + czas[i];
                if(odleglosc[v] < INT32_MAX) continue;
                Queue.push(make_pair(-odle, v));
            }
        }

        if(odleglosc[0] < INT32_MAX) cout << odleglosc[0] << '\n';
        else cout << "-1\n";
    }


    return 0;
}