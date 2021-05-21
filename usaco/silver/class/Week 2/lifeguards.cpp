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
  setIO("lifeguards");
  ll n;
  cin >> n;
  pair<ll, ll> arr[2 * n];
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    arr[2 * i] = {a, i};
    arr[2 * i + 1] = {b, i};
  }
  sort(arr, arr + 2 * n);
  multiset<ll> S;
  ll covered = 0;
  ll last = 0;
  ll alone[n] = {0};
  for (auto &p : arr) {
    if (S.size() == 1) {
      alone[*S.begin()] += p.first - last;
    }
    if (!S.empty()) {
      covered += p.first - last;
    }
    if (S.count(p.second)) {
      S.erase(p.second);
    } else {
      S.insert(p.second);
    }
    last = p.first;
  }
  ll ans = 0;
  for (ll a : alone) {
    ans = max(ans, covered - a);
  }
  cout << ans << endl;
}