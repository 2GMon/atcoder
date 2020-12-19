#include"bits/stdc++.h"
using namespace std;

int month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Main() {
  int N;
  cin >> N;

  for (int i = 1; i <= 12; i++) {
    month[i] += month[i - 1];
  }

  vector<int> day(367, 0);
  // 土日を休日に設定
  for (int i = 1; i <= 366; i++) {
    if (i % 7 == 0 || i % 7 == 1) day[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    int m = 0, d = 0;
    int j;
    for (j = 0; j < (int)s.length() && s[j] != '/'; j++) {
      m = m * 10 + (s[j] - '0');
    }
    for (j += 1; j < (int)s.length(); j++) {
      d = d * 10 + (s[j] - '0');
    }

    int n = month[m - 1] + d;
    while (n <= 366 && day[n] == 1)
      n++;
    day[n] = 1;
  }

  int ans = 0;
  for (int i = 2; i <= 366; i++) {
    if (day[i] == 1)
      day[i] += day[i - 1];
    ans = max(ans, day[i]);
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