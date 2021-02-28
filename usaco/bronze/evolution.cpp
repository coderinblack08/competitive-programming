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

ll n;
vector<string> ch[25];
vector<string> all_ch;

bool crossing(ll a, ll b) {
  ll A = 0, B = 0, AB = 0;
  for (ll i = 0; i < n; i++) {
    vector<string> &v = ch[i];
    bool has_a = false, has_b = false;
    for (ll j = 0; j < v.size(); j++) {
      if (v[j] == all_ch[a]) {
        has_a = true;
      }
      if (v[j] == all_ch[b]) {
        has_b = true;
      }
    }
    if (has_a && has_b) {
      AB++;
    } else if (has_a) {
      A++;
    } else if (has_b) {
      B++;
    }
  }
  return A > 0 && B > 0 && AB > 0;
}

int main() {
  setIO("evolution");
  cin >> n;
  for (ll i = 0; i < n; i++) {
    ll k;
    cin >> k;
    for (ll j = 0; j < k; j++) {
      string s;
      cin >> s;
      ch[i].push_back(s);
      bool found = false;
      for (ll i = 0; i < all_ch.size(); i++) {
        if (all_ch[i] == s) {
          found = true;
        }
      }
      if (!found) {
        all_ch.push_back(s);
      }
    }
  }
  bool ok = true;
  for (ll a = 0; a < all_ch.size(); a++) {
    for (ll b = a + 1; b < all_ch.size(); b++) {
      if (crossing(a, b)) {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}