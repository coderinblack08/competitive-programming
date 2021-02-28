#include <bits/stdc++.h>
#define ll long long
#define all(x) begin(x), end(x)
#define f first
#define s second
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

bool comp (pair<ll, ll>  a, pair<ll, ll> b) { return a.f < b.f; }

int main() {
  setIO("cowqueue");
  ll n, t = 0;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (ll i = 0; i < n; ++i) {
    cin >> v[i].f >> v[i].s;
  }
  sort(all(v), comp);
  for (auto c: v) {
    if (t < c.f) {
      t = c.f + c.s;
    } else {
      t += c.s;
    }
  }
  cout << t << "\n";
  return 0;
}