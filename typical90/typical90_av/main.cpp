#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N, K;
  cin >> N >> K;

  vector<ll> score;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    score.push_back(B);
    score.push_back(A - B);
  }

  sort(score.rbegin(), score.rend());

  ll ans = 0;
  for (int i = 0; i < K; i++) ans += score[i];

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}