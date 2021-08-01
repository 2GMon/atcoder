#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int A(int x) {
  int tmp = x;
  int y = 0;
  while (tmp != 0) {
    y += tmp % 10;
    tmp /= 10;
  }
  return (x + y) % 100000;
}

void Main() {
  int N;
  ll K;
  cin >> N >> K;

  vector<bool> visit(100000, false);

  int z = N;
  int first_len = 0;
  ll i;
  for (i = 0; i < K; i++) {
    if (visit[z]) break;
    first_len++;
    visit[z] = true;
    z = A(z);
  }
  if (i == K) {
    cout << z << endl;
    return;
  }

  int loop_start = z;
  int loop_size = 0;
  do {
    loop_size++;
    z = A(z);
  } while (z != loop_start);
  int idx = (K - first_len) % loop_size;

  z = loop_start;
  for (int i = 0; i < idx; i++) {
    z = A(z);
  }
  cout << z << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}