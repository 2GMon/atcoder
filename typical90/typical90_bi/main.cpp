#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)

void Main() {
  int Q;
  cin >> Q;

  deque<int> deck;
  for (int i = 0; i < Q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      deck.push_front(x);
    } else if (t == 2) {
      deck.push_back(x);
    } else if (t == 3) {
      cout << deck[x - 1] << endl;
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