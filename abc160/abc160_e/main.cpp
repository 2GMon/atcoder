#include"bits/stdc++.h"
using namespace std;

void Main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  vector<pair<int, char>> apples(A + B + C);
  for (int i = 0; i < A; i++) {
    int v;
    cin >> v;
    apples[i] = pair<int, char>(v, 'r');
  }
  for (int i = 0; i < B; i++) {
    int v;
    cin >> v;
    apples[i + A] = pair<int, char>(v, 'g');
  }
  for (int i = 0; i < C; i++) {
    int v;
    cin >> v;
    apples[i + A + B] = pair<int, char>(v, '?');
  }

  sort(apples.rbegin(), apples.rend());

  long long ans = 0;
  int x = 0, y = 0, num = 0;
  for(int i = 0; i < A + B + C; i++) {
    pair<int, char> a = apples[i];
    if (a.second == 'r' && x < X) {
      ans += a.first;
      x++;
      num++;
    }
    if (a.second == 'g' && y < Y) {
      ans += a.first;
      y++;
      num++;
    }
    if (a.second == '?') {
      ans += a.first;
      num++;
    }
    if (num == X + Y) break;
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