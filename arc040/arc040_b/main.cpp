#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N, R;
  cin >> N >> R;
  char S[N];
  int last = -1;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    if (S[i] == '.') last = i;
  }

  if (last == -1) {
    cout << 0 << endl;
    return;
  }

  int ans = 0;
  int move = 0;
  for (int i = 0; i <= last - R + 1; i++) {
    if (S[i] == '.') {
      for (int j = 0; j < R; j++) {
        S[i + j] = 'o';
      }
      ans++;
      ans += move;
      move = 0;
    } else if (i == last - R + 1) {
      ans++;
      ans += move;
      move = 0;
    }
    move++;
  }
  if (ans == 0) cout << 1 << endl;
  else cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}