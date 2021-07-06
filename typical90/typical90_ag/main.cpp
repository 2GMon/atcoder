#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int H, W;
  cin >> H >> W;

  if (H == 1 || W == 1) cout << H * W << endl;
  else cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}