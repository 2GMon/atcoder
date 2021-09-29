#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (A % C == 0) cout << A << endl;
  else if (A + C - A % C <= B) cout << A + C - A % C << endl; 
  else cout << -1 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}