#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<int> a(N), b(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }

  long long op_max = 0;
  for (int i = 0; i < N; i++) {
    op_max += (b[i] - a[i]);
  }

  long long op_min = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] >= b[i]) continue;
    long long t = b[i] - a[i];
    if (t % 2 == 1) t = t / 2 + 1;
    else t = t / 2;
    op_min += t;
  }

  if (op_min <= op_max) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}