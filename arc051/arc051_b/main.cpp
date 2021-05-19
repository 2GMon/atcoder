#include"bits/stdc++.h"
using namespace std;

void Main() {
  int K;
  cin >> K;
  if (K == 1) {
    cout << 1 << " " << 1 << endl;
    return;
  }
  long long a, b;
  a = 2; b = 2;
  for (int i = 1; i < K; i++) {
    int tmp = a + b;
    a = b;
    b = tmp;
  }

  cout << a << " " << a + b << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}