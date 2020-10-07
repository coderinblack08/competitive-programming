#include <bits/stdc++.h>
using namespace std;

int n;
bool g[10][10], r[10][10], af[10][10];

void rotate() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[j][n - i - 1] = g[i][j];
    }
  }
}

void reflect() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      r[i][n - j - 1] = g[i][j];
    }
  }
}

void copy() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = r[i][j];
    }
  }
}

bool check() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (af[i][j] != g[i][j])
        return false;
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char a;
      cin >> a;
      if (a == '@')
        g[i][j] = true;
      else
        g[i][j] = false;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char a;
      cin >> a;
      if (a == '@')
        af[i][j] = true;
      else
        af[i][j] = false;
    }
  rotate();
  copy();
  if (check()) {
    cout << 1;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 2;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 3;
    return 0;
  }
  rotate();
  copy();
  reflect();
  copy();
  if (check()) {
    cout << 4;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 5;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 5;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 5;
    return 0;
  }
  rotate();
  copy();
  if (check()) {
    cout << 6;
    return 0;
  }
  cout << 7;
  return 0;
}