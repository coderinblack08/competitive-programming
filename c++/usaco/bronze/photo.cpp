#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("photo");
  ll n;
  cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n - 1; i++) {
    cin >> A[i];
  }
  for (ll a = 1; a < n + 1; a++) {
    vector<ll> B(n);
    set<ll> S;
    B[0] = a;
    S.insert(B[a]);
    bool bad = false;
    for (ll i = 1; i < n; i++) {
      ll ai = A[i - 1] - B[i - 1];
      if (S.count(ai) || !(1 <= ai && ai <= n)) {
        bad = true;
        break;
      }
      S.insert(ai);
      B[i] = ai;
    }
    if (bad) {
      continue;
    }
    for (ll i = 0; i < n; i++) {
      cout << B[i];
      if (i < n - 1) {
        cout << ' ';
      } else {
        cout << "\n";
      }
    }
  }
  return 0;
}