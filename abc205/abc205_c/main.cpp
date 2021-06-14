#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll A, B, C;
  cin >> A >> B >> C;

  if (A >= 0 && B >= 0) {
    if (A < B) cout << "<" << endl;
    else if (A > B) cout << ">" << endl;
    else cout << "=" << endl;
  } else if (A >= 0) {
    if (C % 2 == 0) {
      if (A < -B) cout << "<" << endl;
      else if (A > -B) cout << ">" << endl;
      else cout << "=" << endl;
    } else {
      cout << ">" << endl;
    }
  } else {
    if (C % 2 == 0) {
      if (-A < B) cout << "<" << endl;
      else if (-A > B) cout << ">" << endl;
      else cout << "=" << endl;
    } else {
      cout << "<" << endl;
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