#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  string s;
  ll lc = 0, uc = 0;
  cin >> s;
  for (char c: s) {
    if (c >= 'a' && c <= 'z') {
      lc++;
    } else {
      uc++;
    }
  }
  if (lc < uc) {
    transform(s.begin(), s.end(),s.begin(), ::toupper);
  } else {
    transform(s.begin(), s.end(),s.begin(), ::tolower);
  }
  cout << s;
  return 0;
}