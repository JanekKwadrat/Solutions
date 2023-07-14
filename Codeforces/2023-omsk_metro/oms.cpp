/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1843/F1 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 200'010;
int t, T;

int n;
int parent[N];
vector<int> children[N];

struct Vertex {
    int value;
    int sum;
    int min_sum, max_sum;
    int min_path, max_path;
} vertex[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> T;
        n = 1;
        children[1].clear();
        vertex[1].value = 1;
        vertex[1].sum = 1;
        vertex[1].min_sum = 0, vertex[1].max_sum = 1;
        vertex[1].min_path = 0, vertex[1].max_path = 1;
        while(T--) {
            char c;
            cin >> c;
            if(c == '+') {
                int v, x;
                cin >> v >> x;
                n++;
                parent[n] = v;
                children[v].push_back(n);
                children[n].clear();

                vertex[n].value = x;
                vertex[n].sum = vertex[v].sum + x;
                vertex[n].min_sum = min(vertex[v].min_sum, vertex[n].sum);
                vertex[n].max_sum = max(vertex[v].max_sum, vertex[n].sum);

                vertex[n].min_path = min(vertex[v].min_path, vertex[n].sum - vertex[n].max_sum);
                vertex[n].max_path = max(vertex[v].max_path, vertex[n].sum - vertex[n].min_sum);
            } else if(c == '?') {
                int u, v, k;
                cin >> u >> v >> k;
                if(vertex[v].min_path <= k && k <= vertex[v].max_path)
                    cout << "Yes\n";
                else cout << "No\n";
            } else return 101;
        }
    }

    return 0;
}