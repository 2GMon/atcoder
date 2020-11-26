#include"bits/stdc++.h"
using namespace std;

void Main() {
  string s;
  cin >> s;

  vector<pair<char, string>> cards;
  vector<string> S, H, D, C;
  char comp;
  for (int i = 0; i < (int)s.length(); i++) {
    char mark = s[i];
    string number = "";
    if (s[i + 1] == '1') {
      number += s[i + 1];
      number += s[i + 2];
      i += 2;
    } else {
      number = s[i + 1];
      i += 1;
    }
    cards.push_back(pair<char, string>(mark, number));
    if (number == "10" || number == "J" || number == "Q" || number == "K" || number == "A") {
      switch (mark)
      {
      case 'S':
        S.push_back(number);
        if (S.size() == 5) {
          comp = 'S';
          i += s.size();
        }
        break;
      case 'H':
        H.push_back(number);
        if (H.size() == 5) {
          comp = 'H';
          i += s.size();
        }
        break;
      case 'D':
        D.push_back(number);
        if (D.size() == 5) {
          comp = 'D';
          i += s.size();
        }
        break;
      case 'C':
        C.push_back(number);
        if (C.size() == 5) {
          comp = 'C';
          i += s.size();
        }
        break;
      default:
        break;
      }
    }
  }

  if (cards.size() == 5) {
    cout << 0 << endl;
    return;
  }

  for (auto c: cards) {
    char mark = c.first;
    string number = c.second;

    if ((number == "10" || number == "J" || number == "Q" || number == "K" || number == "A") && mark == comp) continue;
      cout << mark << number;
  }
  cout << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}