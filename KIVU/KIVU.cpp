// Source: https://old.ntucoder.net/Problem/Details/93
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);

  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0, j = 0;
  int ans = 0;

  while (i < n && j < m) {
      if (a[i] > b[j]) {
          // Ghép cặp thành công
          ++ans;
          ++i;
          ++j;
      } else {
          // Nam chưa đủ cao, thử người tiếp theo
          ++i;
      }
  }

  cout << ans << '\n';

  return 0;
}
