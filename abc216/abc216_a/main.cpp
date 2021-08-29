#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  string S;
  cin >> S;

  int i = 0;
  for (i = 0; i < S.length(); i++) {
    if (S[i] != '.') cout << S[i];
    else break;
  }
  int y = S[++i] - '0';
  if (y <= 2) cout << "-" << endl;
  else if (y <= 6) cout << endl;
  else cout << "+" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}