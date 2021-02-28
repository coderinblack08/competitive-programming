#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int n, k;
bool pieces[10][8][8];

bool getValue(int piece, int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n)
    return false;
  else
    return pieces[piece][x][y];
}

int main() {
  setIO("bcs");
  cin >> n >> k;
  bool goal[n][n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '#')
        goal[i][j] = true;
      else
        goal[i][j] = false;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      string s;
      cin >> s;
      for (int k = 0; k < n; k++) {
        if (s[k] == '#')
          pieces[i][j][k] = true;
        else
          pieces[i][j][k] = false;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      for (int idx = -n + 1; idx < n; idx++) {
        for (int idy = -n + 1; idy < n; idy++) {
          for (int jdx = -n + 1; jdx < n; jdx++) {
            for (int jdy = -n + 1; jdy < n; jdy++) {
              bool good = true;
              for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                  bool ivalue = getValue(i, idx + x, idy + y);
                  bool jvalue = getValue(j, jdx + x, jdy + y);
                  if (ivalue && jvalue) {
                    good = false;
                  }
                  bool cell = false;
                  if (ivalue || jvalue)
                    cell = true;
                  if (goal[x][y] != cell) {
                    good = false;
                  }
                }
              }
              if (good)
                cout << i + 1 << " " << j + 1;
            }
          }
        }
      }
    }
  }
  return 0;
}