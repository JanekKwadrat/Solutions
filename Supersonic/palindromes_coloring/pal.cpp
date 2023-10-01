#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t;
int n, k;
char s[N];
int letter_count[256];
int doubles_count;
int singles_count;
int answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s + 1;

        for(char c = 'a'; c <= 'z'; ++c) letter_count[c] = 0;
        for(int i = 1; i <= n; ++i) letter_count[s[i]]++;

        doubles_count = 0;
        singles_count = 0;
        for(char c = 'a'; c <= 'z'; ++c) {
            doubles_count += letter_count[c] / 2;
            singles_count += letter_count[c] % 2;
        }

        answer = 2 * (doubles_count / k);
        answer += (2 * (doubles_count % k) + singles_count) >= k;

        cout << answer << '\n';
    }

    return 0;
}
