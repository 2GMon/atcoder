#include"bits/stdc++.h"
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  set<int> ans;
  for (int i = 0; i < N; i++) {
    while (a[i] % 2 == 0) a[i] /= 2;
    ans.insert(a[i]);
  }

  cout << ans.size() << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}