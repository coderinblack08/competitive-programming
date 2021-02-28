#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ll x, n, a;
  cin >> x >> n;
  multiset<ll> L;
  set<ll> S;
  L.insert(x);
  S.insert(0); S.insert(x);
  for (ll i = 0; i < n; ++i) {
    cin >> a;
    auto it = S.upper_bound(a);
    ll upper = *it; it--;
    ll lower = *it;
    L.erase(L.find(upper - lower));
    L.insert(upper - a); L.insert(a - lower);
    S.insert(a);
    cout << *(L.rbegin()) << endl;    
  }
  return 0;
}