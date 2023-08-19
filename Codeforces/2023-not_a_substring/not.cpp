#include <bits/stdc++.h>
using namespace std;

int t;
string u, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> u;
        v = "";

        bool ok1 = false, ok2 = false;

        for(int i = 1; i < u.length(); ++i) {
            if(u[i] == u[i-1]) ok1 = true;
            if(u[i] == '(' && u[i-1] == ')') ok2 = true;
        }

        if(ok1) {
            for(int i = 0; i < u.length(); ++i) v += "()";
        } else if(ok2) {
            for(int i = 0; i < u.length(); ++i) v += "(";
            for(int i = 0; i < u.length(); ++i) v += ")";
        }

        if(v == "") cout << "NO\n";
        else {
            cout << "YES\n";
            cout << v << '\n';
        }
    }

    return 0;
}
