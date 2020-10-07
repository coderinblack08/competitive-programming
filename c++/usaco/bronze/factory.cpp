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
  setIO("factory");
  ll n;
  cin >> n;
  vector<ll> incoming(n + 1, 0), outgoing(n + 1, 0);
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    outgoing[a]++;
    incoming[b]++;
  }
  ll answer = -1;
  for (ll i = 1; i <= n; ++i) {
    if (outgoing[i] == 0 && answer != -1) {
      answer = -1;
      break;
    }
    if (outgoing[i] == 0) {
      answer = i;
    }
  }
  cout << answer;
  return 0;
}