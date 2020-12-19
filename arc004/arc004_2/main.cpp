#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;
  vector<int> d(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> d[i];
    sum += d[i];
  }

  cout << sum << endl;
  long long minimum = sum;
  bool close = true;
  for (int i = 0; i < N; i++) {
    if (sum - d[i] < d[i]) {
      close = false;
      minimum = min(minimum, d[i] - (sum - d[i]));
    }
  }
  if (close) cout << 0 << endl;
  else cout << minimum << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}