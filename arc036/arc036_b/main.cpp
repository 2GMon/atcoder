#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> h(N);

  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  int ans = 0;
  int i;
  int start = 0;
  if (N <= 2) {
    cout << N << endl;
    return;
  }
  for (i = 2; i < N; i++) {
    if (h[i - 2] > h[i - 1] && h[i - 1] < h[i]) {
      ans = max(ans, i - 1 - start + 1);
      start = i - 1;
    } else if (i == N - 1) {
      ans = max(ans, i - start + 1);
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