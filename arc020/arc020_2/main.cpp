#include"bits/stdc++.h"
using namespace std;

void Main() {
  int n, c;
  cin >> n >> c;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = n * c;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (i == j) continue;

      int diff = 0;
      for (int k = 0; k < n; k++) {
        if (k % 2 == 0 && a[k] != i) diff++;
        if (k % 2 == 1 && a[k] != j) diff++;
      }

      ans = min(ans, diff);
    }
  }

  cout << ans * c << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}