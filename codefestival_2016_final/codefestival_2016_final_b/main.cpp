#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int N;
  cin >> N;

  vector<int> ans;
  ll sum = 0;
  int r = 0;
  for (int i = 1; sum < N; i++) {
    sum += i;
    r = i;
  }
  for (int i = 1; i <= r; i++) {
    if (i != sum - N) cout << i << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}