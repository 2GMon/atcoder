#include"bits/stdc++.h"
using namespace std;

int N;
vector<int> x, y, h;

void Main() {
  cin >> N;

  x.resize(N);
  y.resize(N);
  h.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      int tmp = 0;
      for (int k = 0; k < N; k++) {
        if (h[k] != 0) {
          tmp = h[k] + abs(x[k] - i) + abs(y[k] - j);
          break;
        }
      }
      bool suc = true;
      for (int k = 0; k < N; k++) {
        if (max(tmp - abs(x[k] - i) - abs(y[k] - j), 0) != h[k]) {
          suc = false;
          break;
        }
      }
      if (suc) {
        cout << i << " " << j << " " << tmp << endl;
        return;
      }
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}