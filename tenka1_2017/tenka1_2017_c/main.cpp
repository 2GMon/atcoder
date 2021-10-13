#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  ll N;
  cin >> N;

  for (int h = 1; h <= 3500; h++) {
    for (int n = 1; n <= 3500; n++) {
      ll a = N * h * n;
      ll b = 4 * h * n - N * (h + n);
      if (b != 0 && a / b > 0 && a % b == 0) {
        cout << h << " " << n << " " << a / b << endl;
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