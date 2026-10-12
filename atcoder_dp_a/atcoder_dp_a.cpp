// Source: https://oj.vnoi.info/problem/atcoder_dp_a
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int &x : h) cin >> x;

    int prev2 = 0;
    int prev1 = abs(h[1] - h[0]);

    for (int i = 2; i < n; i++) {
        int cur = min(
            prev1 + abs(h[i] - h[i - 1]),
            prev2 + abs(h[i] - h[i - 2])
        );

        prev2 = prev1;
        prev1 = cur;
    }

    cout << prev1 << '\n';
}
