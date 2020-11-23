#include"bits/stdc++.h"
using namespace std;

void Main() {
  int R, C, D;
  cin >> R >> C >> D;

  int ans = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int A;
      cin >> A;
      if (D % 2 == (i + j) % 2 && (i + j) <= D) {
        ans = max(ans, A);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}