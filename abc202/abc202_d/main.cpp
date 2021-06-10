#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

ll cmb(int a, int b) {
  ll ans = 1;
  rep(i, min(b, a - b)) {
    ans *= (a - i);
    ans /= (i + 1);
  }

  return ans;
}

void Main() {
  ll A, B, K;
  cin >> A >> B >> K;

  int len = A + B;
  for (int i = 0; i < len; i++) {
    if (A == 0 && B > 0) {
      cout << 'b';
      B--;
    }
    else if (A > 0 && B == 0) {
      cout << 'a';
      A--;
    }
    else if (K <= cmb(A + B - 1, A - 1)) {
      cout << 'a';
      A--;
    } else {
      cout << 'b';
      K -= cmb(A + B - 1, A - 1);
      B--;
    }
  }
  cout << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}