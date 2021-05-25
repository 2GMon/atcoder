#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N, D, K;
  cin >> N >> D >> K;

  vector<pair<int, int>> LR(D);
  for (int i = 0; i < D; i++) {
    int L, R;
    cin >> L >> R;
    LR[i] = pair<int, int>(L, R);
  }

  vector<pair<int, int>> ST(K);
  for (int i = 0; i < K; i++) {
    int S, T;
    cin >> S >> T;
    ST[i] = pair<int, int>(S, T);
  }

  for (auto st: ST) {
    int S = st.first, T = st.second;
    int ans = 0;
    if (S < T) {
      for (int i = 0; i < D; i++) {
        ans++;
        if (LR[i].first <= S && S <= LR[i].second) {
          if (T <= LR[i].second) break;
          else S = LR[i].second;
        }
      }
    } else {
      for (int i = 0; i < D; i++) {
        ans++;
        if (LR[i].first <= S && S <= LR[i].second) {
          if (T >= LR[i].first) break;
          else S = LR[i].first;
        }
      }
    }

    cout << ans << endl;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}