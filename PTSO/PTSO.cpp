// Source: https://old.ntucoder.net/Problem/Details/81
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
    cin >> n;

    bool first = true;

    for (int i = 2; 1LL * i * i <= n; i++) {
        while (n % i == 0) {
            if (!first) cout << '*';

            cout << i;
            first = false;

            n /= i;
        }
    }

    if (n > 1) {
        if (!first) cout << '*';
        cout << n;
    }

  return 0;
}
