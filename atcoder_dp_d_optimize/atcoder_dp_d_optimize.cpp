// Source: https://oj.vnoi.info/problem/atcoder_dp_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; i++) {
        int w;
        long long v;
        cin >> w >> v;

        // Traverse backwards to avoid reusing an item
        for (int j = W; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[W] << '\n';
    return 0;
}
