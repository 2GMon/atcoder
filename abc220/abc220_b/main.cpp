#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int K;
  cin >> K;
  string A, B;
  cin >> A >> B;

  long long a = 0, b = 0;
  int k = 1;
  for (int i = (int)A.length() - 1; i >= 0; i--) {
    a += (A[i] - '0') * k;
    k *= K;
  }
  k = 1;
  for (int i = (int)B.length() - 1; i >= 0; i--) {
    b += (B[i] - '0') * k;
    k *= K;
  }

  cout << a * b << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}