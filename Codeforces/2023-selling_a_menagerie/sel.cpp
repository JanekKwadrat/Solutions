/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/F */
#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e5+10;
int t, n;
int a[N]; // a[i] = Who is the animal `i` afraid of?
int c[N]; // c[i] = What is the cost of the animal `i`?

int deg[N];
queue<int> Queue;

vector<int> p;

vector<pair<int,int>> sth;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> c[i];

        for(int i = 1; i <= n; ++i) deg[i] = 0;
        for(int i = 1; i <= n; ++i) deg[a[i]]++;
        while(Queue.size() > 0) Queue.pop();
        for(int i = 1; i <= n; ++i) {
            if(deg[i] == 0) {
                Queue.push(i);
            }
        }

        p.clear();
        while(Queue.size() > 0) {
            int i = Queue.front();
            Queue.pop();

            p.push_back(i);

            deg[a[i]]--;
            if(deg[a[i]] == 0)
                Queue.push(a[i]);
        }

        sth.clear();
        for(int i = 1; i <= n; ++i) {
            sth.push_back({c[i], i});
        }
        sort(sth.begin(), sth.end());

        for(pair<int,int> elm : sth) {
            int i = elm.second;
            if(deg[i] == 0) continue;
            //cout << i << '\n';

            int j = a[i];
            while(true) {
                deg[j] = 0;
                p.push_back(j);
                if(j == i) break;
                else j = a[j];
            }
        }

        for(int x : p) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
