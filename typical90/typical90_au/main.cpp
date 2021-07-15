#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll MOD = 1e9 + 7;

void Main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;

  vector<int> s(N), t(N);
  for (int i = 0; i < N; i++) {
    s[i] = S[i] == 'R' ? 0 : (S[i] == 'G' ? 1 : 2);
    t[i] = T[i] == 'R' ? 0 : (T[i] == 'G' ? 1 : 2);
  }

  ll ans = 0;
  for (int i = 0 ; i < 3; i++) {
    vector<int> t_(N);
    // 斜めが同色の条件を数列一致判定だけですむように
    // 色がRの場合はG(1) -> B(2), B(2) -> G(1)
    // 色がGの場合はR(0) -> B(2), B(2) -> R(0)
    // 色がBの場合はR(0) -> G(1), G(1) -> R(0)に置き換える
    for (int j = 0; j < N; j++) {
      t_[j] = (i - t[j] + 3) % 3;
    }

    // s_1 == t_n, (s_1, s_2) == (t_(n-1), t(n)), ...の数をカウント
    ll tmp = 1;
    ll hash_s = 0, hash_t = 0;
    for (int j = 0; j < N; j++) {
      hash_s = (hash_s * 3 + s[j]) % MOD;
      hash_t = (hash_t + tmp * t_[N - 1 - j]) % MOD;
      if (hash_s == hash_t) ans++;
      tmp = tmp * 3 % MOD;
    }
    // s_n == t_1, (s_(n - 1), s(n)) == (t_1, t_2), ...の数をカウント
    tmp = 1;
    hash_s = 0, hash_t = 0;
    for (int j = 0; j < N - 1; j++) {
      hash_s = (hash_s + tmp * s[N - 1 - j]) % MOD;
      hash_t = (hash_t * 3 + t_[j]) % MOD;
      if (hash_s == hash_t) ans++;
      tmp = tmp * 3 % MOD;
    }
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