#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

ll n, T;
string s;
vector<pair<ll, ll>> cows(251);
vector<ll> getsInfected(101);

bool consistantWithData(ll patientZero, ll k) {
  vector<ll> handshakes(101, 0);
  vector<int> infected(101, false);
  infected[patientZero] = true;
  for (ll t = 0; t <= 250; t++) {
    ll x = cows[t].first, y = cows[t].second;
    if (x > 0) {
      if (infected[x]) {
        handshakes[x]++;
      }
      if (infected[y]) {
        handshakes[y]++;
      }
      if (handshakes[x] <= k && infected[x]) {
        infected[y] = true;
      }
      if (handshakes[y] <= k && infected[y]) {
        infected[x] = true;
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (infected[i] != getsInfected[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  setIO("tracing");
  cin >> n >> T >> s;
  for (ll i = 1; i <= n; i++) {
    getsInfected[i] = s[i - 1] == '1';
  }
  for (ll i = 0; i < T; i++) {
    ll t2, x, y;
    cin >> t2 >> x >> y;
    cows[t2].first = x;
    cows[t2].second = y;
  }
  vector<int> possibleZero(101, false);
  vector<int> possibleK(252, false);
  for (ll i = 1; i <= n; i++) {
    for (ll k = 0; k <= 251; k++) {
      if (consistantWithData(i, k)) {
        possibleZero[i] = true;
        possibleK[k] = true;
      }
    }
  }
  ll lower = 251, upper = 0, patientZero = 0;
  for (ll i = 0; i <= 251; i++) {
    if (possibleK[i]) {
      upper = i;
    }
  }
  for (ll i = 251; i >= 0; i--) {
    if (possibleK[i]) {
      lower = i;
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (possibleZero[i]) {
      patientZero++;
    }
  }
  cout << patientZero << " " << lower << " ";
  if (upper == 251) {
    cout << "Infinity" << endl;
  } else {
    cout << upper << endl;
  }
  return 0;
}
