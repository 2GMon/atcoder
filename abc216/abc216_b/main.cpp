#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<string> S(N), T(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> T[i];
  }

  map<string, int> m;
  for (int i = 0; i < N; i++) {
    m[S[i] + " " + T[i]]++;
  }

  bool yes = false;
  for (int i = 0; i < N; i++) {
    if (m[S[i] + " " + T[i]] > 1) yes = true;
  }
  if (yes) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}