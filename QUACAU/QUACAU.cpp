// Source: https://old.ntucoder.net/Problem/Details/3307
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int &x : a) cin >> x;

  sort(a.begin(), a.end());

  long long ans = 0;

  while (n > 3) {
      long long t1 = a[0] + 2LL * a[1] + a[n - 1];
      long long t2 = 2LL * a[0] + a[n - 2] + a[n - 1];

      ans += min(t1, t2);
      n -= 2;
  }

  if (n == 3) {
      ans += a[0] + a[1] + a[2];
  } else if (n == 2) {
      ans += a[1];
  } else if (n == 1) {
      ans += a[0];
  }

  cout << ans << '\n';

  return 0;
}
