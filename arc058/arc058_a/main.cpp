#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N;
  int K;
  cin >> N >> K;

  vector<bool> D(10, true);
  for (int i = 0; i < K; i++) {
    int tmp;
    cin >> tmp;
    D[tmp] = false;
  }

  int ans = 0;
  for (int i = N; i <= 10 * N; i++) {
    int tmp = i;
    bool res = true;
    while(tmp > 0) {
      int j = tmp % 10;
      if (D[j] == false) res = false;
      tmp /= 10;
    }
    if (res) {
      ans = i;
      break;
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