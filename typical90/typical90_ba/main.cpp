#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> A(1600);
int N;

int query(int i) {
  if (i < 1 || N < i) return -1;
  if (A[i] != -1) return A[i];
  int ans;
  cout << "? " << i << endl;
  cin >> ans;
  A[i] = ans;
  return ans;
}

void Main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N;

    for (int i = 0; i < 1600; i++) A[i] = -1;

    int ans = 0;
    int l = 1, r = N;
    for (int i = 0; i <= 20; i++) {
      int c = (l + r) / 2;
      int f1 = query(c), f2 = query(c + 1);
      ans = max({ans, f1, f2});
      if (f1 < f2) l = c;
      else r = c;
    }
    cout << "! " << ans << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}