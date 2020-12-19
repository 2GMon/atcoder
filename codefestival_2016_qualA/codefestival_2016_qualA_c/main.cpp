#include"bits/stdc++.h"
using namespace std;

void Main() {
  string s;
  cin >> s;
  int K;
  cin >> K;

  int pos = 0;
  while (K > 0 && pos < s.length()) {
    if (s[pos] == 'a') {
      pos++;
      continue;
    }
    int toa = ('z' + 1) - s[pos];
    if (toa <= K) {
      s[pos] = 'a';
      K -= toa;
    }
    pos++;
  }

  pos = s.length() - 1;
  if (K > 0) {
    s[pos] = s[pos] + K % 26;
    if (s[pos] > 'z') {
      s[pos] = 'a' + (s[pos] - 'z');
    }
  }

  cout << s << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}