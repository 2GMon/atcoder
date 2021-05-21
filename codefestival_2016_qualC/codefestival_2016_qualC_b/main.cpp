#include"bits/stdc++.h"
using namespace std;

void Main() {
  int K, T;
  cin >> K >> T;

  int maxT = 0, maxNum = 0;
  for (int i = 0; i < T; i++) {
    int tmp;
    cin >> tmp;
    if (tmp > maxNum) {
      maxNum = tmp;
      maxT = i;
    }
  }

  cout << max(maxNum - 1 - (K - maxNum), 0) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}