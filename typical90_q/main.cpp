#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class BIT {
public:
  int size_ = 1;
  vector<ll> bit;

  void init(int size) {
    size_ = size + 2;
    bit.resize(size_ + 2, 0);
  }
  void add(int pos, long long x) {
    pos++;
    while (pos <= size_) {
      bit[pos] += x;
      pos += (pos & -pos);
    }
  }
  long long sum(int pos) {
    long long s = 0; pos++;
    while (pos >= 1) {
      s += bit[pos];
      pos -= (pos & -pos);
    }
    return s;
  }
};

void Main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> L(M + 1), R(M + 1);
  for (int i = 1; i <= M; i++) {
    cin >> L[i] >> R[i];
  }

  /*
  ll ans = 0;
  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j < M; j++) {
      if (L[i] < L[j] && L[j] < R[i] && R[i] < R[j]) ans++;
      if (L[j] < L[i] && L[i] < R[j] && R[j] < R[i]) ans++;
    }
  }
  cout << ans << endl;
  */
  ll ans1 = 0;
  vector<ll> sum1(N + 1, 0);
  for (int i = 1; i <= M; i++) {
    sum1[L[i]]++;
    sum1[R[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    ans1 += sum1[i] * (sum1[i] - 1) / 2;
  }

  ll ans2 = 0;
  vector<ll> sum2(N + 1, 0), sum3(N + 1, 0);
  for (int i = 1; i <= M; i++) {
    sum2[R[i]]++;
    sum3[L[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    sum2[i] += sum2[i - 1];
  }
  for (int i = 1; i <= N; i++) {
    ans2 += sum2[i - 1] * sum3[i];
  }

  ll ans3 = 0;
  vector<pair<ll, ll>> vec;
  for (int i = 1; i <= M; i++) {
    vec.push_back(pair<ll, ll>(R[i], L[i]));
  }
  sort(vec.begin(), vec.end());
  BIT bit;
  bit.init(N + 2);
  for (int i = 0; i < vec.size(); i++) {
    ll cl = vec[i].second, cr = vec[i].first;
    ll ret = bit.sum(cr) - bit.sum(cl);
    ans3 += ret;
    bit.add(cl, 1);
  }

  ll ans = M * (M - 1) / 2;
  cout << ans - ans1 - ans2 - ans3 << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}