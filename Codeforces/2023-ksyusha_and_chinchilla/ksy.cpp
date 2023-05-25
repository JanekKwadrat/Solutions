/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1833/G */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n;
vector<pair<int, int>> neighbors[N];
int edge[N];

int root;
int parent[N];
//vector<int> children[N];

int counter[N];
int subtree[N];

bool visited[N];
queue<int> Queue;

bool ans;
vector<int> cut;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int u = 1; u <= n; ++u) {
            neighbors[u].clear();
            //children[u].clear();
        }
        for(int i = 1; i <= n-1; ++i) {
            int u, v;
            cin >> u >> v;
            neighbors[u].push_back(make_pair(v, i));
            neighbors[v].push_back(make_pair(u, i));
        }

        root = 1;
        Queue.push(root);
        for(int u = 1; u <= n; ++u) {
            visited[u] = false;
            counter[u] = 0;
        }
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            visited[u] = true;
            for(auto el : neighbors[u]) {
                int v = el.first, i = el.second;
                if(visited[v]) {
                    parent[u] = v;
                    edge[u] = i;
                } else {
                    //children[u].push_back(v);
                    counter[u]++;
                    Queue.push(v);
                }
            }
        }

        for(int u = 1; u <= n; ++u) {
            if(counter[u] == 0)
                Queue.push(u);
            subtree[u] = 1;
        }
        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            if(u == root) continue;
            int v = parent[u];
            subtree[v] += subtree[u];
            counter[v]--;
            if(counter[v] == 0)
                Queue.push(v);
        }

        cut.clear();
        for(int u = 1; u <= n; ++u) {
            if(u == root) continue;
            if(subtree[u] % 3 == 0) cut.push_back(edge[u]);
        }

        ans = n % 3 == 0 && cut.size() == n / 3 - 1;
        if(!ans) cout << "-1\n";
        else {
            cout << cut.size() << '\n';
            for(int i : cut) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}