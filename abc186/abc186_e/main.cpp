#include"bits/stdc++.h"
using namespace std;

template <typename T>
T gcd(T  a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <typename T>
T extgcd(T a, T b, T* x, T* y) {
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    }
    T g = extgcd(b, a % b, x, y);
    T tmpx = *x;
    *x = *y;
    *y = tmpx - a / b * *y;
    return g;
}

void Main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    long long N, S, K;
    cin >> N >> S >> K;
    // S + K * x = 0 (mod N)
    // K * x = -S (mod N)
    // x = -S * K^(-1) (mod N)
    long long d = gcd<long long>(gcd<long long>(N, S), K);
    N /= d;
    S /= d;
    K /= d;
    long long x, y, g;
    g = extgcd<long long>(K, N, &x, &y);
    if (g != 1) {
      cout << -1 << endl;
    } else {
      cout << ((- S * x) % N + N) % N << endl;
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