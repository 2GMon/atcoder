#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N;
  cin >> N;

  vector<string> C(N);
  cout << 0 << endl;
  cin >> C[0];
  if (C[0] == "Vacant") return;

  int l = 0, r = N;
  for (int i = 1; i < 20; i++) {
    int mid = (l + r) / 2;
    cout << mid << endl;
    cin >> C[mid];
    if (C[mid] == "Vacant") return;
    if ((mid - l) % 2 == 0) {
      if (C[l] == C[mid]) l = mid;
      else r = mid;
    } else {
      if (C[l] == C[mid]) r = mid;
      else l = mid;
    }
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}