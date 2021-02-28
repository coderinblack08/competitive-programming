#include <bits/stdc++.h>
using namespace std;

void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

int main() {
  setIO();
  string s, heard;
  cin >> s >> heard;
  int cur = 0, ans = 1;
  for (int i = 0; i < heard.length(); i++) {
    do {
      cur++;
      if (cur == 26) {
        cur = 0;
        ans++;
      }
    } while (s[cur] != heard[i]);
  }
  cout << ans << endl;
  return 0;
}