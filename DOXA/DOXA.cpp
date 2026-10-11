// Source: https://old.ntucoder.net/Problem/Details/105
#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int a[N], x[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }

  int min_cost = INT_MAX, ans = 0;
  for (int i = 0; i < n; i++) {
    min_cost = min(min_cost, x[i]);
    // cout << "min_cost: " << min_cost << endl;
    ans += a[i] * min_cost;
  }

  cout << ans;

  return 0;
}
