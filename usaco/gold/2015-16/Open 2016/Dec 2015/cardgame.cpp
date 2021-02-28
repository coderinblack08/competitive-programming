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
  setIO("cardgame");
  int n;
  cin >> n;
  vector<bool> used(n * 2);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    used[a[i]] = true;
  }

  sort(a.begin(), a.begin() + n / 2);
  sort(a.begin() + n / 2, a.end());
  rotate(a.begin(), a.begin() + n / 2, a.end());

  vector<int> b;
  for (int i = 0; i < 2 * n; i++) {
    if (!used[i]) {
      b.push_back(i);
    }
  }
  int ans = 0;
  for (int i = n / 2, j = n / 2; i < n; i++, j++, ans++) {
    while (j < n && b[j] < a[i]) {
      j++;
    }
    if (j == n) {
      break;
    }
  }
  for (int i = n / 2 - 1, j = n / 2 - 1; i >= 0; i--, j--, ans++) {
    while (j >= 0 && b[j] > a[i]) {
      j--;
    }
    if (j == -1) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}