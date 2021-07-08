#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
T gcd(T  a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Main() {
  ll A, B;
  cin >> A >> B;

  ll r = B / gcd(A, B);
  if (r > 1000000000000000000LL / A) cout << "Large" << endl;
  else cout << r * A << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}