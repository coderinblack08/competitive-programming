/*
ID: kevinlu4
TASK: transform
LANG: C++11
*/

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int n;
char g1[10][10], g2[10][10], temp[10][10];

void read() {
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> g1[i][j];
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> g2[i][j];
    }
  }
}

bool same() {
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (g1[i][j] != g2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void rotate() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[j][(n - 1) - i] = g1[i][j];
    }
  }
}

void copy() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g1[i][j] = temp[i][j];
    }
  }
}

void reflect() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][(n - 1) - j] = g1[i][j];
    }
  }
}

int main() {
  setIO("transform");
  cin >> n;
  read();

  rotate();
  copy();
  if (same()) {
    cout << 1 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 2 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 3 << endl;
    return 0;
  }

  rotate();
  copy();
  // reset the grid
  reflect();
  copy();
  if (same()) {
    cout << 4 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 5 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 5 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 5 << endl;
    return 0;
  }

  rotate();
  copy();
  if (same()) {
    cout << 6 << endl;
    return 0;
  }

  cout << 7 << endl;
  return 0;
}