#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  int n;
  string s;
  cin >> n >> s;
  for(int guess = 1; guess <= n; guess++) {
    bool good = true;
    for(int i = 0; i + guess <= n; i++) {
      for(int j = 0; j < i; j++) {
        if(s.substr(i, guess) == s.substr(j, guess)) {
          good = false;
        }
      }
    }
    if(good) {
      cout << guess << "\n";
      return 0;
    }
  }
}