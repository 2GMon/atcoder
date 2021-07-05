#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  ll N, K;
  cin >> N >> K;

  map<ll, ll> dp;
  vector<int> num;
  // N未満の正の整数の中で考えているので、Nをインクリメント
  N++;
  while (N) {
    num.push_back(N % 10);
    N /= 10;
  }
  reverse(num.begin(), num.end());

  // 上の桁がNと一致しているときの桁の積
  ll seki = 1;
  // 1桁目に0を入れないようにするため
  bool first = true;
  // Nを1桁ずつ処理していく
  for (int d : num) {
    map<ll, ll> pre;
    swap(dp, pre);

    // N以下が確定しているときの遷移
    for (auto p : pre) {
      for (int i = 0; i < 10; i++) {
        dp[p.first * i] += p.second;
      }
    }
    // 上の桁がNと一致しているときの遷移(今の桁の数字はd)
    // 初めて桁がNと異なるときに場合の数を1足す
    for (int i = 0; i < d; i++) {
      if (i == 0 && first) continue;
      dp[seki * i] += 1;
    }
    // Nよりも桁数が少ない場合の先頭の数が決まった時に場合の数を1足す
    if (!first) {
      for (int i = 1; i <= 9; i++) {
        dp[i] += 1;
      }
    }
    seki *= d;
    first = false;
  }

  ll ans = 0;
  for (auto p : dp) {
    if (p.first <= K) ans += p.second;
  }

  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}