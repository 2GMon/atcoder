#include"bits/stdc++.h"
using namespace std;

void Main() {
  int x, y;
  cin >> x >> y;

  int N;
  cin >> N;

  vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  double ans = 10000000;
  for (int i = 0; i < N; i++) {
    int ax = X[i], ay = Y[i];
    int bx = X[i + 1 < N ? i + 1 : 0], by = Y[i + 1 < N ? i + 1 : 0];
    bx -= ax; by -= ay;
    int tx = x - ax, ty = y - ay;
    ax = 0; ay = 0;
    double theta = atan2(by, bx);
    double dist = sin(-theta) * tx + cos(-theta) * ty;
    /*
    cout << "A = (" << ax << ", " << ay << "), B = (" << bx << ", " << by << "), ";
    cout << "takahashi = (" << tx << ", " << ty << ")" << endl;
    cout << "theta = " << -theta << endl;
    cout << "distX = " << cos(-theta) * tx - sin(-theta) * ty << endl;
    cout << "distY = " << dist << endl;
    cout << endl;
    */
    ans = min(ans, abs(dist));
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