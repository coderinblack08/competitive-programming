#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, r = "";
  cin >> s;
  for (ll i = 0; i < s.length(); ++i) {
    if (s[i] == '.') {
      r += '0';
    } 
    if (s[i] == '-' && s[i + 1] == '.' && i != s.length() - 1) {
      r += '1';
      ++i;
    }
    if (s[i] == '-' && s[i + 1] == '-' && i != s.length() - 1) {
      r += '2';
      ++i;
    }
  }
  cout << r << "\n";
  return 0;
}