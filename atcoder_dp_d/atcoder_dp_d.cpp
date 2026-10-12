// Source: https://oj.vnoi.info/problem/atcoder_dp_d
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

   int N, W;
    cin >> N >> W;

    vector<int> w(N + 1);
    vector<long long> v(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<long long>> dp(
        N + 1, vector<long long>(W + 1, 0)
    );

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            // Do not choose item i
            dp[i][j] = dp[i - 1][j];

            // Choose item i
            if (j >= w[i]) {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - 1][j - w[i]] + v[i]
                );
            }
        }
    }

    cout << dp[N][W] << '\n';

  return 0;
}
