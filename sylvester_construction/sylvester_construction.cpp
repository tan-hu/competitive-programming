// Source: https://open.kattis.com/problems/sylvester
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    unsigned long long n, x, y;
    int w, h;

    cin >> n >> x >> y >> w >> h;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {

        unsigned long long row = y + i;
        unsigned long long col = x + j;

        int value = (__builtin_popcountll(row & col) & 1) ? -1 : 1;

        cout << value;

        if (j + 1 < w)
          cout << ' ';
      }

      cout << '\n';
    }

    cout << '\n';
  }

  return 0;
}
