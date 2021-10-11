#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

void Main() {
  int N;
  cin >> N;

  vector<int> n;
  cout << 6 << endl;
  cout << 10 << endl;
  cout << 15 << endl;
  for (int a = 12; a <= 10000; a += 6) n.push_back(a);
  for (int a = 20; a <= 10000; a += 10) n.push_back(a);
  for (int a = 30; a <= 10000; a += 15) n.push_back(a);
  sort(n.begin(), n.end());

  int i = 3;
  int tmp = 0;
  for (auto a: n) {
    if (i == N) break;
    if (a == tmp) continue;
    cout << a << endl;
    tmp = a;
    i++;
  }
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}