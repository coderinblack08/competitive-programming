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

int main() {
  setIO();
  bool ok[8][8];

  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++) {
      ok[i][j] = s[j] == '.';
    }
  }

  vector<int> vals(8);
  iota(all(vals), 0);  // 0, 1, ..., 7

  int ans = 0;

  do {
    bool works = true;
    vector<int> blocked(16, false);
    for (int i = 0; i < 8; i++) {
      if (!ok[i][vals[i]]) {  // check if square is occupied
        works = false;
      }
    }

    for (int i = 0; i < 8; i++) {
      if (blocked[i + vals[i]]) {  // check top-left to bottom-right "diagonal"
        works = false;
      }
      blocked[i + vals[i]] = true;
    }

    fill(all(blocked), false);

    for (int i = 0; i < 8; i++) {
      if (blocked[i + 7 - vals[i]]) {  // check bottom-left to top-right "diagonal"
        works = false;
      }
      blocked[i + 7 - vals[i]] = true;  // add 7 because of negative values (offset)
    }

    if (works) {
      ans++;
    }
  } while (next_permutation(all(vals)));

  cout << ans << endl;

  return 0;
}