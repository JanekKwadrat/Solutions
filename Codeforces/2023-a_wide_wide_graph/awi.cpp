/*  Jan Zakrzewski
    https://codeforces.com/contest/1805/problem/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
int n;
vector<int> neighbors[N];

int root;
int parent[N];
vector<int> children[N];

int upward_longest[N];
int downward_longest[N];
int downward_second[N];

int excitement[N];
int circus[N];
int answer[N];

bool visited[N];
queue<int> Queue;
int counter[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = 1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }

    for(int u = 1; u <= n; ++u) {
        downward_longest[u] = INT32_MIN;
        downward_second[u] = INT32_MIN;
        counter[u] = children[u].size();
        if(counter[u] == 0) {
            Queue.push(u);
            downward_longest[u] = 0;
        }
    }

    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        if(u == root) continue;
        int v = parent[u];
        downward_second[v] = max(downward_second[v], downward_longest[u] + 1);
        if(downward_longest[v] < downward_second[v]) swap(downward_longest[v], downward_second[v]);
        counter[v]--;
        if(counter[v] == 0) Queue.push(v);
    }

    upward_longest[root] = 0;
    for(int u : children[root]) Queue.push(u);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        for(int v : children[u]) Queue.push(v);
        upward_longest[u] = INT32_MIN;
        int v = parent[u];
        upward_longest[u] = max(upward_longest[u], upward_longest[v] + 1);
        if(downward_longest[v] != downward_longest[u] + 1) upward_longest[u] = max(upward_longest[u], downward_longest[v] + 1);
        else upward_longest[u] = max(upward_longest[u], downward_second[v] + 1);
    }

    for(int u = 1; u <= n; ++u) excitement[u] = max(upward_longest[u], downward_longest[u]);

    for(int i = 1; i <= n; ++i) circus[i] = 0;
    for(int u = 1; u <= n; ++u) circus[excitement[u]]++;
    for(int i = n-1; i >= 1; --i) circus[i] += circus[i+1];
    for(int i = 1; i <= n; ++i) answer[i] = n - max(circus[i], 1) + 1;

    // The following is meant for debugging purposes
    /*for(int u = 1; u <= n; ++u) cout << u << ' '; cout << '\n';
    for(int u = 1; u <= n; ++u) cout << downward_longest[u] << ' '; cout << '\n';
    for(int u = 1; u <= n; ++u) cout << downward_second[u] << ' '; cout << '\n';
    for(int u = 1; u <= n; ++u) cout << upward_longest[u] << ' '; cout << '\n';
    for(int u = 1; u <= n; ++u) cout << excitement[u] << ' '; cout << '\n';
    for(int u = 1; u <= n; ++u) cout << circus[u] << ' '; cout << '\n';*/

    // This is supposed to be the final answer
    for(int u = 1; u <= n; ++u) cout << answer[u] << ' '; cout << '\n';

    return 0;
}