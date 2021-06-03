#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  string S;
  cin >> S;

  map<char, int> count;
  rep(i, S.length()) {
    count[S[i]]++;
  }

  int k = 0;
  for (auto c: count) {
    if (c.second % 2 == 1) k++;
  }

  if (k == 0) cout << S.length() << endl;
  else cout << 2 * ((S.length() - k) / (2 * k)) + 1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}