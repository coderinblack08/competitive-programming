#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll n, a; cin >> n;
  multiset<ll> S;
  for (ll i = 0; i < n; ++i) {
    cin >> a;
    auto it = S.upper_bound(a);
    if (it == S.end()) {
      S.insert(a);
    } else {
      S.erase(it);
      S.insert(a);
    }
  }
  cout << S.size() << endl;
  return 0;
}