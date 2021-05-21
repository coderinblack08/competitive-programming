#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);
  int n, k;
  string s[n];
  cin >> n >> k;
  for(int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  int cur = 0;
  for(int i = 0; i < n; ++i) {
    if(cur + s[i].length() > k) {
      cout << "\n" << s[i];
      cur = s[i].length();
    } else {
      if(cur > 0) {
        cout << " ";
      }
      cout << s[i];
      cur += s[i].length();
    }
  }
  return 0;
}
