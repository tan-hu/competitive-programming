// Source: https://old.ntucoder.net/Problem/Details/93
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long minPrice = LLONG_MAX;
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        long long price;
        cin >> price;

        minPrice = min(minPrice, price);
        ans += 3LL * minPrice;
    }

    cout << ans << '\n';

    return 0;

}