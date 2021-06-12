#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int oa, ab, bc;
  cin >> oa >> ab >> bc;

  double ans = (oa + ab + bc) * (oa + ab + bc) * M_PI;
  if (oa > ab + bc) {
    ans -= (oa - ab - bc) * (oa - ab - bc) * M_PI;
  }
  if (ab > oa + bc) {
    ans -= (ab - oa - bc) * (ab - oa - bc) * M_PI;
  }
  if (bc > oa + ab) {
    ans -= (bc - oa - ab) * (bc - oa - ab) * M_PI;
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