/*  Jan Zakrzewski
    https://codeforces.com/contest/1805/problem/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
constexpr int D = 17;

int n;
vector<int> neighbors[N];
vector<pair<int,int>> edges;
int nmb[N];
int sorted[N];
int zero;
vector<pair<int,int>> links;
int height[N];
int climb[N][D];
int root;
vector<int> children[N];
queue<int> Queue;
bool visited[N];
int answer[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
        edges.push_back(make_pair(u, v));
    }
    for(int u = 1; u <= n; ++u) {
        cin >> nmb[u];
        sorted[u] = u;
    }
    sort(&sorted[1], &sorted[n]+1, [&](int u, int v) -> bool { return nmb[u] > nmb[v]; });

    zero = 0;
    for(int i = 1; i <= n; ++i) {
        if(i > 1 && nmb[sorted[i]] == nmb[sorted[i-1]]) continue;
        if(i+1 > n || nmb[sorted[i]] != nmb[sorted[i+1]]) continue;
        if(i+2 <= n && nmb[sorted[i]] == nmb[sorted[i+2]]) {
            zero = max(zero, nmb[sorted[i]]);
            break;
        }
        links.push_back(make_pair(sorted[i], sorted[i+1]));
    }

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = 1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) climb[u][0] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }
    for(int i = 0; i < D; ++i) climb[root][i] = 0;
    Queue.push(root);
    height[root] = 0;
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        for(int i = 1; i < D; ++i) {
            climb[u][i] = climb[climb[u][i-1]][i-1];
        }
        for(int v : children[u]) {
            Queue.push(v);
            height[v] = height[u] + 1;
        }
    }
    function<int(int,int)> lowest_common_ancestor = [&](const int uu, const int vv) -> int {
        int u = uu, v = vv;
        if(height[u] < height[v]) swap(u, v);
        for(int i = D-1; i >= 0; --i) {
            if(height[u] - (1 << i) >= height[v])
                u = climb[u][i];
        }
        if(u == v) return u;
        for(int i = D-1; i >= 0; --i) {
            if(climb[u][i] != climb[v][i]) {
                u = climb[u][i];
                v = climb[v][i];
            }
        }
        u = climb[u][0];
        //v = climb[v][0];
        return u;
    };


    for(int u = 1; u <= n; ++u) answer[u] = -1;
    {
        int u = -1, v = -1;
        for(auto elm : links) {
            if(u == -1 && v == -1) {
                u = elm.first;
                v = elm.second;
                continue;
            }
            int u_oth = elm.first;
            int v_oth = elm.second;
            int val = nmb[u_oth];

            int u_next, v_next;
            int w = lowest_common_ancestor(u, v);
            
            {
                int u_next1 = lowest_common_ancestor(u_oth, u);
                int u_next2 = lowest_common_ancestor(u_oth, v);
                if(height[u_next1] < height[w]) u_next1 = w;
                if(height[u_next2] < height[w]) u_next2 = w;
                if(u_next1 == w) u_next = u_next2;
                else u_next = u_next1;
                int v_next1 = lowest_common_ancestor(v_oth, u);
                int v_next2 = lowest_common_ancestor(v_oth, v);
                if(height[v_next1] < height[w]) v_next1 = w;
                if(height[v_next2] < height[w]) v_next2 = w;
                if(v_next1 == w) v_next = v_next2;
                else v_next = v_next1;
            }

            int the_jump = lowest_common_ancestor(u_next, v_next);

            while(true) {
                if(u == u_next || u == v_next) u = the_jump;
                if(u == w) break;
                
                answer[u] = val;
                u = climb[u][0];
            }
            while(true) {
                if(v == u_next || v == v_next) v = the_jump;
                if(v == w) break;
                
                answer[v] = val;
                v = climb[v][0];
            }

            u = u_next, v = v_next;
        }

        if(u == -1 && v == -1) {
            for(int u = 1; u <= n; ++u)
                answer[u] = zero;
        } else {
            int w = lowest_common_ancestor(u, v);
            while(true) {
                if(u == w) break;
                else {
                    answer[u] = zero;
                    u = climb[u][0];
                }
            }
            while(true) {
                if(v == w) break;
                else {
                    answer[v] = zero;
                    v = climb[v][0];
                }
            }
            for(int u = 1; u <= n; ++u) {
                if(answer[u] == -1)
                    answer[u] = nmb[links[0].first];
            }
        }
    }

    for(auto elm : edges) {
        int u = elm.first;
        int v = elm.second;
        if(climb[u][0] == v) cout << answer[u] << '\n';
        else cout << answer[v] << '\n';
    }

    return 0;
}