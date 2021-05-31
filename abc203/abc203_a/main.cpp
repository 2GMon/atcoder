#include"bits/stdc++.h"
using namespace std;

void Main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];

  sort(a, a + 3);
  if (a[0] == a[1]) cout << a[2] << endl;
  else if (a[1] == a[2]) cout << a[0] << endl;
  else cout << 0 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}