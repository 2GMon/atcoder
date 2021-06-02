#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;

  rep(i, H) {
    rep(j, W) {
      if (j < A && i < B) cout << 0;
      else if (j >= A && i < B) cout << 1;
      else if (j < A && i >= B) cout << 1;
      else if (j >= A && i >= B) cout << 0;
    }
    cout << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}