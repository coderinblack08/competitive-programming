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

const int MX = 1e5 + 1;
int v[26], prefix[MX], suffix[MX + 1];

int main() {
  setIO();
  int n, q;
  string s;
  cin >> n >> q >> s;
  for (int c = 0; c < 26; c++) {
    v[c] = -1;
  }
  for (int i = 1; i <= n; i++) {
    int cur = s[i - 1] - 'A';
    for (int c = 0; c < 26; c++) {
      v[c] = min(v[c], cur);
    }
    prefix[i] = prefix[i - 1];
    if (v[cur] < cur) {
      prefix[i]++;
    }
    v[cur] = cur;
  }
  for (int c = 0; c < 26; c++) {
    v[c] = -1;
  }
  for (int i = n; i >= 1; i--) {
    int cur = s[i - 1] - 'A';
    for (int c = 0; c < 26; c++) {
      v[c] = min(v[c], cur);
    }
    suffix[i] = suffix[i + 1];
    if (v[cur] < cur) {
      suffix[i]++;
    }
    v[cur] = cur;
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << prefix[x - 1] + suffix[y + 1] << endl;
  }
  return 0;
}