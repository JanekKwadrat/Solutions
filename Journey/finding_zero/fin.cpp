#include <bits/stdc++.h>
using namespace std;

inline void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
inline int query(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << '\n';
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
inline void answer(int i, int j) {
    cout << "! " << i << ' ' << j << '\n';
    cout.flush();
}

int t, n;

inline vector<int> solver(const vector<int>& before) {
    vector<int> after;
    if(before.size() <= 2) after = before;
    else if(before.size() == 3) {
        bool ok[5] = {false, true, true, true, true};
        if(before[0] <= 4) ok[before[0]] = false;
        if(before[1] <= 4) ok[before[1]] = false;
        if(before[2] <= 4) ok[before[2]] = false;
        if(ok[1]) after = solver({before[0], before[1], before[2], 1});
        else if(ok[2]) after = solver({before[0], before[1], before[2], 2});
        else if(ok[3]) after = solver({before[0], before[1], before[2], 3});
        else if(ok[4]) after = solver({before[0], before[1], before[2], 4});
    } else if(before.size() == 4) {
        int i = before[0];
        int j = before[1];
        int k = before[2];
        int l = before[3];

        int ans_jkl = query(j, k, l);
        int ans_kli = query(k, l, i);
        int ans_lij = query(l, i, j);
        int ans_ijk = query(i, j, k);

        int Max = ans_jkl;
        if(ans_kli > Max) Max = ans_kli;
        if(ans_lij > Max) Max = ans_lij;
        if(ans_ijk > Max) Max = ans_ijk;

        bool ok_i = true;
        bool ok_j = true;
        bool ok_k = true;
        bool ok_l = true;

        if(ans_jkl == Max) ok_i = false;
        if(ans_kli == Max) ok_j = false;
        if(ans_lij == Max) ok_k = false;
        if(ans_ijk == Max) ok_l = false;

        if(ok_i) after.push_back(i);
        if(ok_j) after.push_back(j);
        if(ok_k) after.push_back(k);
        if(ok_l) after.push_back(l);
    } else {
        for(int i = 0; i < before.size() - 4; ++i) after.push_back(before[i]);
        vector<int> another = solver({before[before.size()-4], before[before.size()-3], before[before.size()-2], before[before.size()-1]});
        for(int x : another) after.push_back(x);
    }
    return after;
}

int main() {
    init();

    cin >> t;
    while(t--) {
        cin >> n;

        vector<int> indices;
        for(int i = 1; i <= n; ++i) indices.push_back(i);

        while(indices.size() > 2) indices = solver(indices);


        if(indices.size() == 1) answer(indices[0], indices[0]);
        else if(indices.size() == 2) answer(indices[0], indices[1]);
    }

    return 0;
}
