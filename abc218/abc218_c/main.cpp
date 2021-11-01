#include"bits/stdc++.h"
using namespace std;

typedef long long ll;

using Matrix = vector<vector<char>>;

void print(Matrix m) {
  cout << "#################" << endl;
  int N = m.size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << m[i][j];
    }
    cout << endl;
  }
  cout << "#################" << endl;
  cout << endl;
}

bool check(Matrix S, Matrix T) {
  int N = S.size();
  int smini = N, sminj = N, smaxi = 0, smaxj = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (S[i][j] == '#') {
        smini = min(smini, i);
        sminj = min(sminj, j);
        smaxi = max(smaxi, i);
        smaxj = max(smaxj, j);
      }
    }
  }
  int tmini = N, tminj = N, tmaxi = 0, tmaxj = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (T[i][j] == '#') {
        tmini = min(tmini, i);
        tminj = min(tminj, j);
        tmaxi = max(tmaxi, i);
        tmaxj = max(tmaxj, j);
      }
    }
  }
  if (smaxi - smini != tmaxi - tmini || smaxj - sminj != tmaxj - tminj) return false;

  for (int i = 0; i < smaxi - smini; i++) {
    for (int j = 0; j < smaxj - sminj; j++) {
      if (S[smini + i][sminj + j] != T[tmini + i][tminj + j]) return false;
    }
  }
  return true;
}

Matrix rorate(Matrix t) {
  int N = t.size();
  Matrix result = Matrix(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int tmpi, tmpj;
      tmpi = i - N / 2;
      tmpj = j - N / 2;
      if (N % 2 == 0) {
        if (tmpi >= 0) tmpi++;
        if (tmpj >= 0) tmpj++;
      }

      int ni = tmpj, nj = -1 * tmpi;
      
      if (N % 2 == 0) {
        if (ni > 0) ni--;
        if (nj > 0) nj--;
      }
      ni += N / 2;
      nj += N / 2;
      
      result[ni][nj] = t[i][j];
    }
  }
  return result;
}

void Main() {
  int N;
  cin >> N;
  
  Matrix S(N, vector<char>(N)), T(N, vector<char>(N)), TT(N, vector<char>(N));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> S[i][j];
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> T[i][j];
    }
  }
  
  if (check(S, T)) {
    cout << "Yes" << endl;
    return;
  }

  for (int n = 0; n < 3; n++) {
    T = rorate(T);
    
    if (check(S, T)) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}