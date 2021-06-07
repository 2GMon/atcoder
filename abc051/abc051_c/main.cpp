#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  rep(i, ty - sy) { cout << "U"; }
  rep(i, tx - sx) { cout << "R"; }
  rep(i, ty - sy) { cout << "D"; }
  rep(i, tx - sx) { cout << "L"; }
  cout << "L";
  rep(i, ty - sy) { cout << "U"; }
  cout << "U";
  cout << "R";
  rep(i, tx - sx) { cout << "R"; }
  cout << "D";
  cout << "R";
  rep(i, ty - sy) { cout << "D"; }
  cout << "D";
  cout << "L";
  rep(i, tx - sx) { cout << "L"; }
  cout << "U" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}