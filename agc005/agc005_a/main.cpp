#include"bits/stdc++.h"
using namespace std;

void Main() {
  string X;
  cin >> X;

  int ans = 0;
  int s = 0;
  for (int i = 0; i < (int)X.length(); i++) {
    if (s == 0 && X[i] == 'T') {
      ans++;
    }
    else if (X[i] == 'T') {
      ans--;
      s--;
    }
    else if (X[i] == 'S') {
      ans++;
      s++;
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