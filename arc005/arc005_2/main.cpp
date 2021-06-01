#include"bits/stdc++.h"
using namespace std;

void Main() {
  int x, y;
  string W;
  cin >> x >> y >> W;
  x--; y--;
  vector<vector<int>> c(9, vector<int>(9));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char tmp;
      cin >> tmp;
      c[i][j] = tmp - '0';
    }
  }

  int dx, dy;
  if (W == "R") {
    dx = 1; dy = 0;
  } else if (W == "L") {
    dx = -1; dy = 0;
  } else if (W == "U") {
    dx = 0; dy = -1;
  } else if (W == "D") {
    dx = 0; dy = 1;
  } else if (W == "RU") {
    dx = 1; dy = -1;
  } else if (W == "RD") {
    dx = 1; dy = 1;
  } else if (W == "LU") {
    dx = -1; dy = -1;
  } else if (W == "LD") {
    dx = -1; dy = 1;
  }

  for (int i = 0; i < 4; i++) {
    cout << c[y][x];
    x += dx;
    y += dy;
    if (x == -1) {
      x = 1;
      dx *= -1;
    }
    if (x == 9) {
      x = 7;
      dx *= -1;
    }
    if (y == -1) {
      y = 1;
      dy *= -1;
    }
    if (y == 9) {
      y = 7;
      dy *= -1;
    }
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